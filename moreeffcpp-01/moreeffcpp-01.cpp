#include <iostream>
#include <string>

void printDouble(const double & rd)
{
   std::cout << "rd: " << rd << "\n";
}

void printDouble(const double * pd)
{
   if (pd) // check for null pointer
   {
      std::cout << "pd: " << *pd << "\n";
   }
}

int main(void)
{
   // references must refer to an object, pointers don't
   // evil example of "null reference"
   char * pc = 0;
   char & rc = *pc;
   static_cast<void>(rc);//intentionally not used

   //std::string & rs; // error: 'rs' declared as reference but not initialized

   std::string s("xyzzy");
   std::string & rs = s; // rs refers to s
   std::cout << rs << "\n";

   // references might be cheaper because no check for null pointer is needed
   double d = 1.234;
   double & rd = d;
   double * pd = &d;
   printDouble(rd);
   printDouble(pd);

   return 0;
}
