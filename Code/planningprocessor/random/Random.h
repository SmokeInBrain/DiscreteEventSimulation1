#include <math.h>
#include <time.h>
#define MODULUS    2147483647 
#define MULTIPLIER 48271       
#define STREAMS    256           
#define DEFAULT    123456789

class Random{
private:
	static long seed[STREAMS]; 
	static int  stream;          
	static int  initialized;          
public:
	Random();
	double calcRandom(void);
};