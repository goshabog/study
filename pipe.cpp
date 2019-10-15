#include <iostream>
using namespace std;

class Pipe
{
	public:
	  Pipe();
	  Pipe(const int l);
	  ~Pipe();
	  int getLenght();

	private:
      int * lp;		
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	return 0;
}
