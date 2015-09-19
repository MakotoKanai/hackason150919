
enum FairyTypes
{
	None = 0,
	Red = 1,
	Blue = 2,
	Green = 3,
	PieceNone = 4,
	Piece0 = 4,
	Piece1 = 5,
	Piece2 = 6,
	Piece3 = 7,
	AllType
};


class Fairy
{
private:
	int type;

public:
	Fairy(int t) :
		type(t)
	{
	}
	
	void kill() { type = None; }
	bool isAlive() { return type != None; }
	
	int getType() { return type; }
};
