#include "HelloWorldScene.h"

USING_NS_CC;

char* fairySpriteNames[] = {
	"1.png",
	"2.png",
	"3.png",
	"4.png",
	"5.png",
	"6.png",
	"7.png",
	"8.png",
	"9.png",
	"10.png",
	"11.png",
	"12.png",
	"13.png",
};

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

	PhysicsWorld* world = scene->getPhysicsWorld();
	world->setGravity(Vec2(0, 100));
	world->setSpeed(1.0f);
	world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	
	// return the scene
    return scene;
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

	gameInit();

    return true;
}


void HelloWorld::gameInit()
{
	isGameOver = false;
	passedTime = 0.0f;
	score = 0;

	tableOriginX = 10.0f;
	tableOriginY = 10.0f;

	// 妖精配置の初期化
	// ３段目まで初期化する
	for (int i = 0; i < fairyTableWidth; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			int type = rand() / AllType;
			fairy[i][j] = createFairy(type, i, j);
		}
	}
}


void HelloWorld::update(float time)
{
	// 消えるアニメーションの途中か判別して、アニメーションが終了していると判断したら再度呼び直す
	//if (isDeleted)
	{

	}
}

Fairy&& HelloWorld::createFairy(int type, float fx, float fy)
{
	// 妖精スプライト
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* sprite = Sprite::create(fairySpriteNames[0]);
	//sprite->setColor(Color3B::WHITE);
	sprite->setAnchorPoint(Vec2(0.0f, 1.0f));
	//sprite->setTextureRect(Rect(0, 0, 32.0f, 32.0f));
	sprite->setScale(fairyWidth / sprite->getContentSize().width, fairyHeight / sprite->getContentSize().height);
	sprite->setPosition(Vec2(origin.x + fx,
		origin.y + visibleSize.height - fy));

	auto spritePhysics = PhysicsBody::createBox(Size(fairyWidth - 0.5f, fairyHeight - 0.5f));
	spritePhysics->setDynamic(false);
	spritePhysics->setRotationEnable(false);
	sprite->setPhysicsBody(spritePhysics);

	this->addChild(sprite);

	// 妖精クラスの生成
	return Fairy(type, sprite);
}

Fairy&& HelloWorld::createFairy(int type, int ix, int iy)
{
	float fx = tableOriginX + ix * fairyWidth;
	float fy = tableOriginY + iy * fairyHeight;

	return createFairy(type, fx, fy);
}


void HelloWorld::callJudge()
{
	// とりあえず１回呼ぶ
	bool isDeleted = false;// Jadge();

	// 妖精が消されたならアニメーションの時間（１秒）待って、もう一度この関数を呼ぶ
	lastCalledJudge = passedTime;
	checkNextJudge = isDeleted;
}

// 妖精が投げられるかどうか判別
bool HelloWorld::isAbleToThrow()
{
	return checkNextJudge && !isGameOver;
}

void HelloWorld::touchListner()
{
	// 動いているスプライトの取得
	/*auto movingPos = movingFairy.getSprite()->GetPosition();
	int ix = (pos.x - tableOriginX) / fairyWidth;
	int iy = (pos.y - tableOriginY) / fairyHeight;

	// 正常な範囲になるように
	ix = ix < 0 ? 0 : ix >= tableWidth ? tableWidth : ix;
	iy = iy < 0 ? 0 : iy >= tableHeight ? tableHeight : iy;

	// 上に空きがあれば詰める
	while (iy > 0 && fairys[ix][iy - 1].isAlive())
		iy -= 1;

	// 既に存在するなら下に
	while (fairys[ix][iy].isAlive() && (iy += 1) < tableHeight);

	// 判定関数を呼ぶ
	callJudge();*/
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
