# Algorithm-Templates
You're participating in CodeChef-CookOff. You've figured out the algorithm for the solution. But you don't have enough time left to implement the solution. Alas! :(. 

Have you ever faced this kind of situation ? Ever wished there were templates for algorithms like for "for loop", "while loop" and other basic language constructs in c/c++, So that you could just plug and chug afew parameters and get an AC. Then your wish is fulfilled now. I'll share with you my algorithm-templates that I've developed in my short and sweet competitive-programming career! I'll add more as I'll learn more! :)

###PreRequisites

1. Experience with Vim Editor

2. Install Vim-Snippets (Just google it!)

I'll focus on the meat of this repository ;) . Algorithms.


###QuickStart

Getting started is pretty easy. Just Follow me!

1.Change your present working directory:
            
              $ cd ~/.vim/snippets
              
2.You'll see cpp.snippets file there. Just replace that file with my cpp.snippets file(you can get it from above).

###Usage

Below is the complete list of all the algorithms and their IDENTIFERS,  currently supported. You just need to write down the IDENTIFIER OF THE ALGORITHM in VIM while coding, and then press tab! You'll get the template for that algorithm. 
Eg : Say you want to use ModularDivision, then in vim :

                //YOUR CODE
                moddiv + <tabspace>  //moddiv is the IDENTIFIER for ModularDivision
              
and you'll have:

                //YOUR CODE
              	pair<ll,pair<ll,ll> > egcd(ll a, ll b)				//solves ax + by = gcd(a,b) = g
              	{								//returns (g,(x,y))
              		pair<ll,pair<ll,ll> > ret;
              
              		if (a==0)
              		{
              			ret.f = b ;
              			ret.s.f = 0 ;
              			ret.s.s = 1 ;
              		}
              		else
              		{
              			ll g, x, y;
              			pair<ll,pair<ll,ll> > temp = egcd( b%a, a) ;
              			g = temp.f;
              			x = temp.s.f;
              			y = temp.s.s;
              			ret.f = g;
              			ret.s.f = y - (b/a)*x ;
              			ret.s.s = x;
              		}
              
              		return ret;
              	}
              
              	ll modinv(ll den, ll m)
              	{
              		pair<ll,pair<ll,ll> > ans = egcd(den, m) ;
              		if (ans.f == 1)
              		{
              			return (ans.s.f+m) % m ;
              		}
              	}
              
              
              	ll moddiv(ll num, ll den, ll m)		// den and m must be coprime
              	{
              		return (num * modinv(den,m) ) % m ;
              	}

######      You can simply call moddiv(numerator,denominator,modulus) in your code now to get (numerator/denomiantor)%modulus .

###List of Algorithm-Templates currently supported:

                <ALGORITHM-NAME>  :  <ALGORITHM-IDENTIFIER>  

      					Binary Search :  bs
      					
      					Bigint Arithmetic : bigint
      					
      					nCr % m  : 
      								binomial1 = O(nlog(no. of digits in n)), N MUST BE LESS THAN M [finds nCr for all 0<=r<=n in fact vector] (M IS LARGE Prime)  // Modular Division - Euclid Extended theorem 
      								binomial2 = O(m^2logn), N is greater than M. (M IS SMALL)  // Lucas theorem
      
      
      					Classic Segment Tree : cseg
      					
      					2-D Segment Tree : 2dseg
      
      					Convex Hull : hull              // Returns vector of points belonging to hull in anti-clockwise order.
      
      					Disjoint Set datastructure : dsu
      
      					Euler Walk (Convert a rooted tree into array)(write out the vertices in order of their visiting by dfs)(IMP: subtree of any vertex is a subsegment of that permutation)  :  ewalk
      					
      					Geometry problems initial code : geometry
      
      					Modular-Division : moddiv 
      
      					Area of any polygon whose points are given : polygon
      
      					Suffix array and LCP array : suffix
      
      					Time Elapsed : time
      					
      					Gretest Common Divisor(Euclid Algorithm) : gcd

                CodeChef Template : chef
                
                Graph problems initial code : graph
