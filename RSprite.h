#ifndef RSPRITE_H
#define RSPRITE_H

#include "cocos2d.h"

USING_NS_CC;
class RSprite: public Sprite
{
protected:

	void registerListener();//прописываем в интерфейсе регистратор событий
	//Подключение событий к объекту
	//void onEnter();

	//Метод, который вызывается при "прикосновении" к этому объекту
public:
	struct RListener {
		virtual void listen(int tag) = 0;//?????
	};
	
private:
	//std::string _frontName;
	//std::string _backName;
	RListener* _listener;

public:
	CC_SYNTHESIZE_PASS_BY_REF(std::string, _frontName, FrontName);
	CC_SYNTHESIZE_PASS_BY_REF(std::string, _backName, BackName);
	CC_SYNTHESIZE(bool, _openFlag, OpenFlag);

public:
	void show();
	void setListener(RListener* listener) { _listener = listener; }
	void touchEvent(Touch* touch, bool openFlag);
	CREATE_FUNC(RSprite);//???

	static RSprite* create(const std::string& frontName, const std::string& backName);

	virtual bool init() override;//что дает виртуализация функции?
	//virtual  void onEnter() override; {}



	RSprite()
		: _listener(nullptr)//прописываем параметр. какой? зачем?
		, _openFlag(false)
	{

	}

	RSprite(const std::string& frontName, const std::string& backName)
		: _frontName(frontName), _backName(backName)
		, _listener(nullptr)
	{

	}
};

#endif