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

	// �d���z�u�̏�����
	// �R�i�ڂ܂ŏ���������
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
	// ������A�j���[�V�����̓r�������ʂ��āA�A�j���[�V�������I�����Ă���Ɣ��f������ēx�Ăђ���
	//if (isDeleted)
	{

	}
}

Fairy&& HelloWorld::createFairy(int type, float fx, float fy)
{
	// �d���X�v���C�g
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

	// �d���N���X�̐���
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
	// �Ƃ肠�����P��Ă�
	bool isDeleted = false;// Jadge();

	// �d���������ꂽ�Ȃ�A�j���[�V�����̎��ԁi�P�b�j�҂��āA������x���̊֐����Ă�
	lastCalledJudge = passedTime;
	checkNextJudge = isDeleted;
}

// �d�����������邩�ǂ�������
bool HelloWorld::isAbleToThrow()
{
	return checkNextJudge && !isGameOver;
}

void HelloWorld::touchListner()
{
	// �����Ă���X�v���C�g�̎擾
	/*auto movingPos = movingFairy.getSprite()->GetPosition();
	int ix = (pos.x - tableOriginX) / fairyWidth;
	int iy = (pos.y - tableOriginY) / fairyHeight;

	// ����Ȕ͈͂ɂȂ�悤��
	ix = ix < 0 ? 0 : ix >= tableWidth ? tableWidth : ix;
	iy = iy < 0 ? 0 : iy >= tableHeight ? tableHeight : iy;

	// ��ɋ󂫂�����΋l�߂�
	while (iy > 0 && fairys[ix][iy - 1].isAlive())
		iy -= 1;

	// ���ɑ��݂���Ȃ牺��
	while (fairys[ix][iy].isAlive() && (iy += 1) < tableHeight);

	// ����֐����Ă�
	callJudge();*/
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
