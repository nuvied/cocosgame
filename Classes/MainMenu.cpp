#include "MainMenu.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object

	auto colorLayer = LayerColor::create(Color4B(30,40,50,255));
	
	
	this->addChild(colorLayer);

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainMenu::menuCloseCallback, this));
    
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
    
    auto label = Label::createWithTTF("Main menu scene", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

	

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("Windmill Splash 1.png");


    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0,0);

	auto fan = Sprite::create("Windmill Splash-JustFan.png");
	fan->setPosition(sprite->getContentSize().width - 112, sprite->getContentSize().height - 20);
	sprite->addChild(fan);
	//sprite->retain();
	sprite->runAction(ScaleTo::create(4, .7));
	fan->runAction(RepeatForever::create(RotateBy::create(2, 360)));

	scheduleOnce(schedule_selector(MainMenu::onFinishSplash), 5);
    
    return true;
}


void MainMenu::onFinishSplash(float dt)
{
	auto sprite = (Sprite*)this->getChildByTag(0);

	sprite->runAction(MoveTo::create(2, Vec2(70, 30)));
	sprite->runAction(ScaleTo::create(1.8, .3));

}

void MainMenu::InitMenu()
{

}

void MainMenu::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
