//
//  main.cpp
//  thread_test
//
//  Created by mac on 2019/8/25.
//  Copyright © 2019年 yinzhibang. All rights reserved.
//
/*
————————————————
版权声明：本文为CSDN博主「赤云」的原创文章，遵循CC 4.0 by-sa版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/u011124985/article/details/79994293
*/
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <thread>

#include <thread>
#include <thread>
#include <mutex>


#include <thread>
#include <mutex>
#include <iostream>

/*
 linux 线程同步
 互斥锁（mutex）
 条件变量（cond）
 信号量（sem_post sem_wait）
 https://blog.csdn.net/jkx01whg/article/details/78119189
 
 信号量，经典的生产者，消费者模式
 https://www.cnblogs.com/kellerfz/p/7862122.html
 */


void Fun_1();
void Fun_2();
unsigned int counter = 0;
std::mutex mtx;

void Fun_1()
{
    while (true)
    {
        std::lock_guard<std::mutex> mtx_locker(mtx);
        ++counter;
        if (counter < 1000)
        {
            std::cout << "Function 1 counting " << counter << "...\n";
        }
        else
        {
            break;
        }
    }
}

void Fun_2()
{
    while (true)
    {
        std::lock_guard<std::mutex> mtx_locker(mtx);
        ++counter;
        if (counter < 1000)
        {
            std::cout << "Function 2 counting " << counter << "...\n";
        }
        else
        {
            break;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::thread thrd_1(Fun_1);
    std::thread thrd_2(Fun_2);
    thrd_1.join();
    thrd_2.join();
    system("pause");
    return 0;
}

/*
 条件变量
pthread_cond_signal()的一个简单的例子。
pthread_mutex_t count_lock;
pthread_cond_t count_nonzero;
unsigned count;
int gloable_calc =0;
decrement_count () {
    pthread_mutex_lock (&count_lock);
    while(count==0)
        pthread_cond_wait( &count_nonzero, &count_lock);
    count=count -1;
    gloable_calc = gloable_calc + 1;
    pthread_mutex_unlock (&count_lock);
}

increment_count(){
    pthread_mutex_lock(&count_lock);
    if(count==0)
        pthread_cond_signal(&count_nonzero);
    count=count+1;
    gloable_calc = gloable_calc + 1;
    pthread_mutex_unlock(&count_lock);
}
*/



/*
 信号
 #include <iostream>
 #include <pthread.h>
 #include <semaphore.h>
 using namespace std;
 
 static sem_t g_semaphore;
 static const int g_iRunTime = 5000;
 
 void* Fun(void* ptr)
 {
 int iRunTime = 0;
 while(++iRunTime< g_iRunTime)
 {
 sem_wait(&g_semaphore);
 cout<< "Fun() is running!" << endl;
 sem_post(&g_semaphore);
 usleep(100);
 }
 }
 
 
 int main()
 {
 pthread_t hHandle;
 sem_init(&g_semaphore, 0, 1);
 int iRet = pthread_create(&hHandle, NULL, Fun, NULL);        //create a thread;
 if(0 != iRet)
 {
 cout << "Create thread failed!" << endl;
 }
 sleep(1);
 int iRunTime = 0;
 while(++iRunTime<g_iRunTime)
 {
 sem_wait(&g_semaphore);
 cout << "main is running!" << endl;
 sem_post(&g_semaphore);
 usleep(100);
 }
 pthread_join(hHandle, NULL);
 return 0;
 }
 */


/*
 #include <pthread.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdbool.h>
 
 pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
 pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
 bool condition = false;
 
 #define LOG(msg) printf("%s:%s\n",__func__ ,msg);
 
 void* ChildFunc(void* arg){
 int i = 0;
 while(true){
 LOG("Enter");
 pthread_mutex_lock(&mutex);
 LOG("Get Lock");
 printf("%d\n",++i);
 if(0 == i%3){
 condition = true;
 LOG("Begin Send Single");
 pthread_cond_signal(&cond);// 唤醒单个
 LOG("End Send Single");
 }
 sleep(3);
 pthread_mutex_unlock(&mutex);
 LOG("Lose Lock");
 LOG("Leave");
 }
 }
 void MainFunc(){
 while(true){
 LOG("Enter");
 pthread_mutex_lock(&mutex);
 LOG("Get Lock");
 while(!condition){
 LOG("Begin Wait Single");
 pthread_cond_wait(&cond,&mutex);
 LOG("End Wait Single");
 }
 condition = false;
 pthread_mutex_unlock(&mutex);
 LOG("Lose Lock");
 LOG("Leave");
 }
 }
 
 int main(){
 pthread_t tid;
 pthread_create(&tid,NULL,ChildFunc,NULL);
 MainFunc();
 pthread_join(tid,NULL);
 return 0;
 }
 */


//多线程
//c++ 11 的特性

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t _mutex_empty;
pthread_cond_t _cond_empty;
int _count_empty;
pthread_mutex_t _mutex_full;
pthread_cond_t _cond_full;
int _count_full;

//生产者线程处理函数
void *producer(void *args)
{
    while (1)
    {
        pthread_mutex_lock(&_mutex_empty);
        while (_count_empty == 0)
        {
            pthread_cond_wait(&_cond_empty, &_mutex_empty);
        }
        _count_empty--;
        pthread_mutex_unlock(&_mutex_empty);
        
        printf("====produce......\n");
        
        pthread_mutex_lock(&_mutex_full);
        _count_full++;
        pthread_mutex_unlock(&_mutex_full);
        pthread_cond_signal(&_cond_full);
        
        //sleep(rand()%3);
    }
}

//消费者线程处理函数
void *consumer(void *args)
{
    while (1)
    {
        pthread_mutex_lock(&_mutex_full);
        while (_count_full == 0)
        {
            pthread_cond_wait(&_cond_full, &_mutex_full);
        }
        _count_full--;
        pthread_mutex_unlock(&_mutex_full);
        
        printf("====consume......\n");
        
        pthread_mutex_lock(&_mutex_empty);
        _count_empty++;
        pthread_mutex_unlock(&_mutex_empty);
        pthread_cond_signal(&_cond_empty);
        
        //sleep(rand()%3);
    }
}

int main(int argc, char *argv[])
{
    int ret;
    pthread_t thread1;
    pthread_t thread2;
    
    pthread_mutexattr_t mutex_attr;
    pthread_mutexattr_init(&mutex_attr);
    pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&_mutex_empty, &mutex_attr);
    pthread_cond_init(&_cond_empty, NULL);
    _count_empty = 1;// 消费者消耗完毕
    pthread_mutex_init(&_mutex_full, &mutex_attr);
    pthread_cond_init(&_cond_full, NULL);
    _count_full = 0;// 生产者没有生成
    
    //让线程转起来
    
    //创建生产者线程
    ret = pthread_create(&thread1, NULL, producer, NULL);
    if(ret!=0)
    {
        printf("pthread_create error, [%s]\n", strerror(ret));
        return -1;
    }
    
    //创建消费者线程
    ret = pthread_create(&thread2, NULL, consumer, NULL);
    if(ret!=0)
    {
        printf("pthread_create error, [%s]\n", strerror(ret));
        return -1;
    }
    
    //主线程回收子线程
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    pthread_cond_destroy(&_cond_empty);
    pthread_mutex_destroy(&_mutex_empty);
    pthread_cond_destroy(&_cond_full);
    pthread_mutex_destroy(&_mutex_full);
    
    return 0;
}


