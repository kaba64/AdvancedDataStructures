#include <fstream>

using namespace std;

int main(){
  std::ofstream Outfile;
  Outfile.open("outfile.txt");
  Outfile<<"Hello writting to a file in c++!"<<std::endl;
  Outfile.close();
  return 0;
}
