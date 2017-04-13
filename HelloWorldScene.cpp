#include "HelloWorldScene.h"
#include "RSprite.h"
#include <vector>
#include <iostream>
#include <algorithm>


//using namespace std;
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void HelloWorld::checkCards(int tag)
{
	_hits.push_back(tag);
	if (_hits.size() == 2) {
		RSprite* pCard1 = (RSprite*)this->getChildByTag(_hits[0]);//получаем указатель на спрайт по его тэгу
		RSprite* pCard2 = (RSprite*)this->getChildByTag(_hits[1]);
		std::string back1 = pCard1->getFrontName();
		std::string back2 = pCard2->getFrontName();
		if (back1 == back2 && _hits[0] != _hits[1]) {
			pCard1->show();
			pCard2->show();
		}
		_hits.clear();
	}
}

void HelloWorld::listen(int tag)
{
	CCLOG("Touched %d", tag);
	this->checkCards(tag);
}

/*template< typename T >
void printVector(std::vector<T> MyVector) {
	for (int i = 0; i < MyVector.size(); ++i) {
		std::cout << MyVector.at(i) << std::endl;
	}
}*/

void InitOfMyVector(std::vector<String> MyVector, std::string s[]) {
	if (MyVector.size() == sizeof(s))
	{
		int m = sizeof(s);
		for (int i = 0; i < m; i++)
		{
			MyVector[i] = s[i];
			srand(0);
			std::random_shuffle(MyVector.begin(), MyVector.end());
			std::cout << std::endl;
			//s[i] = MyVector[i];
			//std::cout << MyVector.at(i) << std::endl;
		}
	}
}

void InitOfMyBackGround(std::vector<String> BackGround, std::string s2[]) {
	if (BackGround.size() == sizeof(s2))
	{
		int m = sizeof(s2);
		for (int i = 0; i < m; i++)
		{
			BackGround[i] = s2[i];
			srand(0);
			std::random_shuffle(BackGround.begin(), BackGround.end());
			std::cout << std::endl;
			//s[i] = MyVector[i];
			//std::cout << MyVector.at(i) << std::endl;
		}
	}
}

void SecondInitOfString(std::vector<String> MyVector, std::string s[]) {
	for (int i = 0; i < sizeof(s); i++)
	{

		//std::random_shuffle(MyVector.begin(), MyVector.end());
		//std::cout << MyVector.at(i) << std::endl;
	}
}


// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Double Cards", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
	//sprite->setVisible(false);

	//Sprite* card[6] = { };
	std::string s[] = { 
		"card_1.png", "card_2.png", "card_3.png", "card_4.png", "card_5.png", "card_6.png"
	};
	std::string s2[] = { "card_7.png", "card_8.png" };
	//std::string s7 = "card_7.png";
	//std::string s8 = "card_8.png";
	/*for (int n = 0; n < 3; n++)
	{
		for (int i = 0; i < 18; i++)
		{
			int j = i % 6;
			int k = i / 6;
			RSprite* card1 = RSprite::create(s[i], s8);
			Point position1 = Point((j*k + i + 0.5) * visibleSize.width / 6, (j*k + 0.5 + i) * visibleSize.height / 6);
			card1->setPosition(position1);
			card1->setListener(this);
			//card1->setVisible(false);

			this->addChild(card1, 0, i);
		}
	}*/
	
	std::vector<String> MyVector(6);
	std::vector<String> BackGround(2);
	//InitOfMyVector(MyVector, s);
	
	int n = 0;
	while (n < 6)
	{
		for (int i = 0; i < 6; i++)
		{
			int j = i % 6;
			int k = i / 6;
			//int n = rand() % 6;
			//printVector(MyVector);
			//InitOfMyVector(MyVector, s);
			//std::random_shuffle(MyVector.begin(), MyVector.end());
			//std::cout << std::endl;
			InitOfMyVector(MyVector, s);
			RSprite* card1 = RSprite::create(s[i], s2[1]);
			Point position1 = Point((n + k + 0.5) * visibleSize.width / 6, (j + 0.5) * visibleSize.height / 6);
			card1->setPosition(position1);
			card1->setListener(this);
			//card1->setVisible(false);

			this->addChild(card1, 0, i);
		}
		n++;
	}

		//RSprite* card2 = RSprite::create(s[i], s8);
		//Point position2 = Point((j + 0.5) * visibleSize.width / 6, (k + 2.5) * visibleSize.height / 6);
		//card2->setPosition(position2);
		//card2->setListener(this);
		//this->addChild(card2, 0, j*k);

		//RSprite* card3 = RSprite::create(s[i], s8);
		//Point position3 = Point((j + 0.5) * visibleSize.width / 6, (k + 4.5) * visibleSize.height / 6);
		//card3->setListener(this);
		//card3->setPosition(position3);

		//this->addChild(card3, 0, j*k);

		//RSprite* card4 = RSprite::create(s[i], s8);
		//Point position4 = Point((j + 3.5) * visibleSize.width / 6, (k + 0.5) * visibleSize.height / 6);
		//card4->setListener(this);
		//card4->setPosition(position4);

		//this->addChild(card4, 0, j*k);

		//RSprite* card5 = RSprite::create(s[i], s8);
		//Point position5 = Point((j + 3.5) * visibleSize.width / 6, (k + 2.5) * visibleSize.height / 6);
		//card5->setListener(this);
		//card5->setPosition(position5);

		//this->addChild(card5, 0, j*k);

		//RSprite* card6 = RSprite::create(s[i], s8);
		//Point position6 = Point((j + 3.5) * visibleSize.width / 6, (k + 4.5) * visibleSize.height / 6);
		//card6->setListener(this);
		//card6->setPosition(position6);

		//this->addChild(card6, 0, j*k);
	

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
