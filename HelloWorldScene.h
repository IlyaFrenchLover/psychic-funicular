#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "RSprite.h"

class HelloWorld : public cocos2d::Layer, //what the fuck?
	public RSprite::RListener
{
private:
	std::vector<int> _hits;
public:
    static cocos2d::Scene* createScene();

	virtual void listen(int tag);
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	void checkCards(int tag);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
