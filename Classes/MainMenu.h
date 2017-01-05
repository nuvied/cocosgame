#ifndef __MAINMENU_H__
#define __MAINMENU_H__

#include "cocos2d.h"

class MainMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
	void InitMenu();

	void onFinishSplash(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);
};


#endif // __MAINMENU_H__
