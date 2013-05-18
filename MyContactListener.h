//
//  MyContactListener.m
//  brick_tut
//
//  Created by Dumadu Games on 7/11/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import"Box2D.h"
#import<vector>
#import<algorithm>

using namespace std;

struct MyContact
{
    b2Fixture* fixtureA;
    b2Fixture* fixtureB;
    
    //find() method to look for matching objects
    bool operator==(const MyContact& other)const
    {
        return (fixtureA==other.fixtureA) && (fixtureB==other.fixtureB);
    }
    
    
};



class MyContactListener: public b2ContactListener
{
 
    public:
    vector<MyContact> contacts;
    

    MyContactListener();
    ~MyContactListener();
    
    virtual void  BeginContact(b2Contact* contact);
    virtual void  EndContact(b2Contact* contact);
    //virtual void  PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
    //virtual void  PostSolve(b2Contact* contact,const b2Manifold* oldManifold);
    
};