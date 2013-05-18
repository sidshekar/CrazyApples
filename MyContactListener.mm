#import "MyContactListener.h"

MyContactListener::MyContactListener():contacts()
{}

MyContactListener::~MyContactListener() 
{}

void MyContactListener::BeginContact(b2Contact* contact){

    MyContact myContact = { contact->GetFixtureA(), contact->GetFixtureB() };
    contacts.push_back(myContact);
}


void MyContactListener::EndContact(b2Contact* contact) {
    
    MyContact myContact = { contact->GetFixtureA(), contact->GetFixtureB() };
    
    std::vector<MyContact>::iterator pos;
    pos = std::find(contacts.begin(), contacts.end(), myContact);
    
    if (pos != contacts.end()) {
        contacts.erase(pos);
    }
}

//void  PreSolve(b2Contact* contact, const b2Manifold* oldManifold){}

//void  PostSolve(b2Contact* contact,const b2Manifold* oldManifold){}