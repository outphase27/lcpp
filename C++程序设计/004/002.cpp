//
//  002.cpp
//  ncpp
//
//  Created by zhaoshen liu on 13/5/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//

MyInt & operator - (int a) {
    nVal -= a;
    return *this;
}
