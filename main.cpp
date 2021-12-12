/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n) : value(v), name(n) {} //1
    int value; //2
    std::string name; //3
};

struct Comparison                               //4
{
    T* compare(T* a, T* b) //5
    {
        if( a != nullptr && b != nullptr )
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float a { 0 }, b { 0 };
    float updateValues(float* updated)      //12
    {
        if( updated != nullptr )
        {
            std::cout << "U's a value: " << this->a << std::endl;
            this->a = *updated;
            std::cout << "U's a updated value: " << this->a << std::endl;
            while( std::abs(this->b - this->a) > 0.001f )
            {
                this->b += 0.5f;
            }
            std::cout << "U's b updated value: " << this->b << std::endl;
            std::cout << "a = " << this->a << std::endl;
            std::cout << "b = " << this->b << std::endl;
            return this->b * this->a;
        }
        else
        {
            std::cout << "'updated' is nullptr" <<  std::endl;
            return 0;
        }
    }
};

struct P
{
    static float updateValues(U* that, float* updated)        //10
    {
        if( that != nullptr && updated != nullptr )
        {    
            std::cout << "U's a value: " << that->a << std::endl;
            that->a = *updated;
            std::cout << "U's a updated value: " << that->a << std::endl;
            while( std::abs(that->b - that->a) > 0.001f )
            {
                /*
                write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                */
                that->b += 0.5f;
                std::cout << "a = " << that->a << std::endl;
                std::cout << "b = " << that->b << std::endl;
            }
            std::cout << "U's b updated value: " << that->b << std::endl;
            return that->b * that->a;
        } 
        else
        {
            std::cout << "'updated' is nullptr" <<  std::endl;
            return 0;
        }   
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T x(10 , "x");                                             //6
    T y(2 , "y");                                             //6
    
    Comparison f;                                            //7
    auto* smaller = f.compare(&x, &y);                              //8
    if( smaller != nullptr )    
    {    
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << P::updateValues(&u1, &updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.updateValues( &updatedValue ) << std::endl;
}
