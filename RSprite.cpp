#include "RSprite.h"

USING_NS_CC;


//---------------------------------------------------------------------------------
RSprite* RSprite::create(const std::string& frontName, const std::string& backName)
{
	RSprite *pRet = new(std::nothrow) RSprite(frontName, backName);
	if (pRet && pRet->init())//????
	{
		pRet->autorelease();//????


		//���������� Event Listener � �������� �������
		//pRet->onEnter();

		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}


	return nullptr;
}

void RSprite::show()
{
	_openFlag = true;
	Sprite* card_2 = (Sprite*)this->getChildByTag(2);
	card_2->setVisible(false);
}

void RSprite::touchEvent(Touch* touch, bool openFlag)
{

	Sprite* card_2 = (Sprite*)this->getChildByTag(2);

	//card_2->setVisible(false);

	Point position = touch->getLocation();//�������� ���������� �������������
	Rect rect = card_2->getBoundingBox();//�������� ���������� ����� ������������ �������
	position = this->convertToNodeSpace(position);//� ��� �����?


	//��������� ���� �� ������������� � ������� �������
	if (rect.containsPoint(position))
	{
		card_2->setVisible(!openFlag);
		if (_listener != nullptr && !openFlag) {
			_listener->listen(this->getTag());
		}
	// �������� ������� � ������������� ���������� ����� �������.
	}

	//CCLOG("onTouchBegan started... %d", this->getTag());
}

//-------------------------------------------------------------------------------------
void RSprite::registerListener()
{
	//������ ��������� ��������� ��������� �������
	auto listener = EventListenerTouchOneByOne::create();
	//listener->setSwallowTouches(true);

	// ������������ ������ ������ �������������
	listener->onTouchBegan = [=](Touch* touch, Event* event)
	{
		if (_openFlag == true)  { return false; }
		this->touchEvent(touch, true);
		return true;
	};

	// ������� �����������
	listener->onTouchMoved = [=](Touch* touch, Event* event)
	{
		//	 ���� ������
	};

	// ������� ���������� �������������
	listener->onTouchEnded = [=](Touch* touch, Event* event)
	{
		// ���� ������
		this->touchEvent(touch, false);
	};

	// ������������ ���������, ������ �������� - ��������� �� ������ � ��������
	// ����� ���������� ���������
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
};

bool RSprite::init()
{
	/*RSprite(const std::string& frontName, const std::string& backName)
	: _frontName(frontName), _backName(backName)*/
	bool bres = Sprite::init();

	Sprite* card_1 = Sprite::create(_frontName);
	this->addChild(card_1, 0, 1);
	Sprite* card_2 = Sprite::create(_backName);
	//card_2->setPosition(Point(20, 20));
	this->addChild(card_2, 0, 2);
	//card_2->setVisible(false);

	//
	registerListener();
	return true;
}

//---------------------------------------------------------------------------------
/*void RSprite::touchEvent(Touch* touch)
{
CCLOG("touched MySprite");
}*/
//--------------------------------------------------------------------------------
/*void RSprite::onEnter()
{
Sprite::onEnter();
//  ������ ��������� ��������� ��������� �������

};*/
