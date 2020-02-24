//
//  main.cpp
//  c_practise_0001
//  weakptr lock 理解
//
//  Created by mingliang8 on 2020/2/20.
//  Copyright © 2020 mingliang8. All rights reserved.
//

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

class testTask{
public:
    int taskId;
};

using testTaskPtr = std::shared_ptr<testTask>;

void observe(std::weak_ptr<int> weak)
{
    if (auto observe = weak.lock()) {
        std::cout << "\tobserve() able to lock weak_ptr<>, value=" << *observe << "\n";
    } else {
        std::cout << "\tobserve() unable to lock weak_ptr<>\n";
    }
}

void observe_c(std::weak_ptr<testTask> weak)
{
    if (auto observe = weak.lock()) {
        std::cout << "\tobserve_c() able to lock weak_ptr<>, addr=" << observe << "\n";
    } else {
        std::cout << "\tobserve_c() unable to lock weak_ptr<>\n";
    }
}

int main()
{
    std::weak_ptr<int> weak;
    std::cout << "weak_ptr<> not yet initialized\n";
    observe(weak);
 
    {
        auto shared = std::make_shared<int>(42);
        weak = shared;
        std::cout << "weak_ptr<> initialized with shared_ptr.\n";
        observe(weak);
    }
 
    std::cout << "shared_ptr<> has been destructed due to scope exit.\n";
    observe(weak);
    
    
   
    std::unordered_map<std::string,testTaskPtr> test_map;
    
    auto test_share = std::make_shared<testTask>();
    std::cout << "weak_ptr<> class initialized with shared_ptr.\n";
    observe_c(test_share);
    test_map["test"] = test_share;
    test_map.erase("test");
    std::cout << "weak_ptr<> class erase with shared_ptr.\n";
    observe_c(test_share);
    
    test_share = nullptr;
    std::cout << "test_share = nullptr \n";
    observe_c(test_share);
   // test_map.insert (std::make_pair<std::string,testTask>("test_share",test_share));
    
}


