//
//  main.cpp
//  curve_node
//
//  Created by mingliang8 on 2020/2/25.
//  Copyright © 2020 mingliang8. All rights reserved.
//


#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

/*
 {"duration_ms": 734, "bandwidth_kbps": 5544, "latency_ms": 20},
 {"duration_ms": 1000, "bandwidth_kbps": 9665, "latency_ms": 20},
 {"duration_ms": 1001, "bandwidth_kbps": 11967, "latency_ms": 20},
 */

class CurveNode;
using CurveNodePtr = std::shared_ptr<CurveNode>;

class CurveNode {
public:
    CurveNode(int64_t start, int64_t end, int64_t duration ,int64_t bandwidth,int32_t unit);
    virtual ~CurveNode();
    
    int64_t start() const {return mStartMs;}
    int64_t end() const {return mEndMs;}
    int64_t duration() const {return mDurationMs;}
    int64_t bandwidth() const {return mBandwidth;}
    int64_t speed() {return mSpeed;}
    int64_t unit() {return mUnit;}
    int32_t count() {return mCount;}
    int32_t leftBw() {return mLeftBw;}
    
    void setApeed(int64_t speed){
       // kbps to Byte
        mSpeed = speed;// * 1024 / 8;
    }
    void setCount(int32_t count){
        mCount = count;
    }
    
    void setLeftBw(int32_t size){
        mLeftBw = size;
    }
    
    void setMoreArea(int64_t area){
        
    }
    
    void setUnitArea(int64_t area){
        
    }
protected:

    
private:
    int64_t mDurationMs;  //ms
    int64_t mBandwidth; //kbps
    int64_t mStartMs; //ms
    int64_t mEndMs; //ms
    //华丽分割线 上面为原始波形，下面为按照最小精度转化后的节点

    int64_t mSpeed;//最小精度下，应该产出多少数据 Byte
    int64_t mUnit;//最小精度
    int32_t mCount;//原始波形的一个点，被最小精度分割后，一共分割了多少个点
    int32_t mLeftBw;//最小精度下，分割剩余的点
};


CurveNode::CurveNode(int64_t start, int64_t end, int64_t duration ,int64_t bandwidth, int32_t unit)
:mStartMs(start)
,mEndMs(end)
,mDurationMs(duration)
,mBandwidth(bandwidth)
,mUnit(unit)
{
    
}

CurveNode::~CurveNode()
{
    
}
//bw kbps
//duration ms
int64_t toArea(int64_t bw , int64_t duration){
    int64_t area = 0;
    int64_t bwByte = bw * 1024 / 8 ;
    area = bwByte * duration / 1000;
    return area;
}

int64_t lMoreArea = 0;
int64_t lNeedArea = 0;
int64_t lNeedDur = 0;
int64_t idx = 0;
int main(int argc, const char * argv[]) {
    
    int64_t duration[3]={734,1000,1001};
    int64_t bandwidth[3]{5544,9665,11967};
    int32_t unit = 50;
    int64_t lastTime = 0;
    int64_t mDuration = 0;
    int64_t nStart = 0;
    int64_t nDuration = 0;
    int64_t nBandWidth = 0;
    int64_t nEnd = 0;
    int32_t mUnitMs = 50;
    //class 相关的deque
    std::deque<CurveNodePtr> mInNodes;
    std::deque<CurveNodePtr> mOutNodes;
    
    for(int i = 0; i<3 ;i++){
        nStart = lastTime;
        nDuration = duration[i];
        mDuration += nDuration;
        
        nBandWidth= bandwidth[i];
        nEnd = nDuration + nStart;
        lastTime = nEnd;
        printf("read_node=%d dur=%lld | start,end=[%lld,%lld] | bw=%lld \n",i,nDuration,nStart,nEnd,nBandWidth);
        auto node = std::make_shared<CurveNode>(nStart,nEnd,nDuration,nBandWidth,unit);
        mInNodes.push_back(node);
    }
    
    
    
    //两个相邻的点进行补齐，如果第一个点不足，第二个点补齐
    //第二个点补齐之后，再继续按照第一个点的方法计算
    //补齐的方法，1.补齐时间 2.速度按照两个点的平均计算
    
    for(int i = 1;i<=mInNodes.size();i++){
        CurveNodePtr lNode = mInNodes[i-1];//取第一个点
        CurveNodePtr rNode = mInNodes[i];//取第二个点
        
        auto lBw = lNode->bandwidth(); //第一个节点的速率kbps
        auto lDur = lNode->duration(); //第一个节点的持续总时间时间 ms，如果作为下一个点的时候需要减去补偿点的时间
        if(lNeedDur > 0){
            lDur = lDur - lNeedDur;
        }
    
        auto lArea = toArea(lBw,lDur);//同理计算补偿点的时间，计算补偿点的面积
        if(lNeedArea > 0){
            lArea= lArea - lNeedArea;
        }
          
        auto lCount = lDur / unit;//可以整除的点
        
        auto lMoreDur = lDur % unit;//多余的点的持续时间
        if(lMoreDur > 0 && rNode){ //计算多余的点的面积和下一个点需要面积组成unit 的面积
            lMoreArea = toArea(lBw,lMoreDur);
            
            int64_t rBw = rNode->bandwidth();
            lNeedDur = unit - lMoreDur;
            lNeedArea = toArea(rBw, lNeedDur);
        }else if(lMoreDur > 0){
            lMoreArea = toArea(lBw,lMoreDur);
            lNeedDur = 0;
            lNeedArea = 0;
        }else{
            lNeedDur = 0;
            lNeedArea = 0;
        }
    
        auto lUnitArea = (lArea - lMoreArea) / lCount; //可以整除的，每一个细化的点的面积
        for(int m=0;m<lCount;m++){
            auto node = std::make_shared<CurveNode>(lNode->start(),lNode->end(),lNode->duration(),lNode->bandwidth(),mUnitMs);
            printf("idx[%d,%lld] (start,end)=[%lld,%lld] (dur,bw,uarea)=%lld,%lld,%lld area(more,need)=(%lld,%lld)\n",i,idx, lNode->start(),lNode->end(),lNode->duration(),lNode->bandwidth(),lUnitArea,lMoreArea,lNeedArea);
            node->setUnitArea(lUnitArea);
            idx++;
            mOutNodes.push_back(node);
        }
        
        if(lMoreDur > 0 && lNode){//计算补偿的点的面积
            auto node = std::make_shared<CurveNode>(lNode->start(),lNode->end(),lNode->duration(),lNode->bandwidth(),mUnitMs);
            auto lExtUnitArea = lMoreArea + lNeedArea;
            printf("-idx[%d,%lld] (start,end)=[%lld,%lld] (dur,bw,uarea)=%lld,%lld,%lld area(more,need)=(%lld,%lld)\n",i,idx, lNode->start(),lNode->end(),lNode->duration(),lNode->bandwidth(),lExtUnitArea,lMoreArea,lNeedArea);
            node->setUnitArea(lExtUnitArea);
            idx++;
            mOutNodes.push_back(node);
        }
    }
  

    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
