#ifndef Homo_Sapience_h
#define Homo_Sapience_h
#include "human.h"

enum Religion {Christianity,Islam,Ateism};						        

class HomoSapience: Human
{
private:
	Religion _religion;
public:
	void Work() override;
	void Dance() override;
	void Party() override;

	Religion getReligion();
	void setReligion(Religion);


};


#endif //Homo_Sapience_h
