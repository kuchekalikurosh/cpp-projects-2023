#include <iostream>
#include <list>
#include <initializer_list>

using namespace std;

//struct term to keep track of all terms (coefficient and exponent)
struct Term
{
   double coef;
   int power;
      
   Term &operator *= (Term t) {
      coef *= t.coef;
      power += t.power; 
      return *this;
   }
};


class Polynomial
{
   list<Term> terms;

   public:
      Polynomial() {

   }
   
   Polynomial(initializer_list<Term> L) {
      //ranged-based for loop 
      for (Term t : L) {
         addTerm(t); 
      } 
   }

   void add(const Polynomial &P) { 
      for (Term t : P.terms) {
         addTerm(t); 
      }
   }

   void multiply(const Polynomial &P) {
      Polynomial result;
      
      for (Term t : P.terms) {
         Polynomial temp = *this;
         for (Term &e : temp.terms) e *= t;;
         result.add(temp);
      }
      terms = result.terms;
   }

   void addTerm(Term t) {
      if (terms.size() == 0 || t.power < terms.back().power) { 
         terms.push_back( t ); 
         return; 
      } 
      for (auto it = terms.begin(); it != terms.end(); it++) {
         if (t.power == it->power) { 
            it->coef += t.coef; 
            return; 
         }
         if (t.power > it->power) { 
            terms.insert(it, t); 
            return; 
         }
      }
   }

   friend ostream &operator << (ostream &out, const Polynomial &P)
   {
      if (P.terms.size() == 0) {
         out << 0;
      }
      
      bool first = true;
      
      for (Term t : P.terms) {
         if ( !first && t.coef >= 0.0 ) {
            out << "+";
         }
         
         first = false;
         out << t.coef;
         
         if (t.power >  1) {
            out << "x^" << t.power;
         } 
         else if (t.power == 1) {
            out << "x";
         }
      }
      return out;
   }
};

int main() {
    
   //1 + 2x reordered as 2x + 1
   Polynomial P({{1.0, 0}, {2.0, 1}});
    
   //5x^2 + 3
   Polynomial Q({{5.0,2}, {3.0,0}});

   cout << "P = " << P << "\n";
   cout << "Q = " << Q << "\n";
   
   Polynomial R = P;   
   R.add(Q);    
   cout << "P + Q = " << R << "\n";
   
   Polynomial S = P;   
   S.multiply(Q);    
   cout << "P * Q = " << S << "\n";
}