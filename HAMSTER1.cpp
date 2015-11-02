// problem: http://www.spoj.com/problems/HAMSTER1/
// solution by rodo
#include<bits/stdc++.h>
using namespace std;
const double PI = M_PI;
const double EPS = 1e-12;
double v0, k1, k2;
double f(double alpha)
{
    return k2*((v0*v0*sin(alpha)*sin(alpha))/20.0) + k1*((v0*v0*sin(2*alpha))/10.0);
}
int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        cin>>v0>>k1>>k2;
        double r=PI/2., l=0;
        while(r-l>EPS)
        {
            double m1 = l + (r - l) / 3.0;
            double m2 = r - (r - l) / 3.0;
            if (f (m1) < f (m2)) // f - convex function
                l = m1;
            else
                r = m2;
        }
        printf("%.3f %.3f\n", r, f(r));
    }    
}

