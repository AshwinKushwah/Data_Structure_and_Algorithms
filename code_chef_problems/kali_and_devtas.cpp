/*
The apocalyptic demon Kali is on a rampage. The ground shudders under his feet, trees shrivel and animals and birds scurry away from his path. In order to save the universe from devastation, all the devtas led by devraj Indra decide to meditate to please Lord Vishnu so that he appears in the form of Kalki, his last avatar, and kill the demon.

Each devta can sit in meditation at a particular place on Swarglok (the heaven). Considering Swarglok as a 2-dimensional plane, the position of each devta is a fixed point with integer coordinates. The positions of all the devtas are distinct from each other.

While meditating the devtas connect to each other by means of astral projections - metaphysical threads that connect one devta to another. They must do so in such a way to satisfy two criteria:

    Each devta must be able to connect to every other devta by following a path of astral projections.
    No subgroup of devtas may be connected by a cycle of astral projections.

In simple terms, the astral projections must form a tree connecting all devtas.

What needs to be optimized ?

Once the devtas have taken their positions and are connected as a single group to start meditation, a ring of influence is formed around each devta. This ring is centered at the position of the devta, and has a radius equal to the Euclidean distance from this devta to the furthest devta directly connected via an astral projection.

Since different devtas have their own supernatural powers (Indra is the rain god, Agni is the fire god,Varuna is the water god, Vayu is the air god , etc), the influence ring of each devta has an adverse effect on all other devtas which lie within or on this ring. In other words, the efficiency of a devta to perform meditation decreases as the number of influence rings that include him increases.

For each devta Di, define Ci as the number of influence rings that include or touch Di (including their own). Now devraj Indra wants the devtas to connect in such a manner so as to minimize the maximum value of Ci over all devtas. So he has sent a message to Bhulok (the earth) and he needs help from the best programmers on the planet.
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
 
using namespace std;
 
class UF    {
    int *id, cnt, *sz;
public:
	// Create an empty union find data structure with N isolated sets.
    UF(int N)   {
        cnt = N;
	id = new int[N];
	sz = new int[N];
        for(int i=0; i<N; i++)	{
            id[i] = i;
	    sz[i] = 1;
	}
    }
    ~UF()	{
	delete [] id;
	delete [] sz;
    }
	// Return the id of component corresponding to object p.
    int find(int p)	{
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
 
    bool inSameSet(int x , int y)
    {
    	return find(x) == find(y);
    }
	// Replace sets containing x and y with their union.
    void merge(int x, int y)	{
        int i = find(x);
        int j = find(y);
        if (i == j) return;
		
		// make smaller root point to larger one
        if   (sz[i] < sz[j])	{ 
		id[i] = j; 
		sz[j] += sz[i]; 
	} else	{ 
		id[j] = i; 
		sz[i] += sz[j]; 
	}
        cnt--;
    }
 
	// Return the number of disjoint sets.
    int count() {
        return cnt;
    }
};
 
struct edge
{
	edge(int a , int b , int _w): d1(a),d2(b),w(_w){}
	int d1;
	int d2;
	double w;
};
 
struct Compare
{
	bool operator () (const edge & a , const edge & b)
	{
		return (a.w > b.w);
	}
};
 
typedef priority_queue <edge , vector<edge> , Compare> Heap;
 
int main()
{
	int T , N , N2, x , y;
	double wt;
	vector <pair <int,int> > V;
 
	scanf("%i" , &T);
 
	while(T--)
	{
		V.clear();
		scanf("%i" , &N);
		
		N2 = N;
		
		while(N2--)
		{
			scanf("%i%i" , &x , &y);
			V.push_back(pair<int,int>(x,y));
		}

		Heap H;
 
		for(int i = 0 ; i<N ; i++)
			for(int j = i+1 ; j<N ; j++)
			{
				wt = sqrt(pow((V[j].first - V[i].first),2) + pow((V[j].second - V[i].second),2));
				H.push(edge(i,j,wt));
			}
	
		UF S(N);
 
		while(S.count() != 1)
		{
			edge e = H.top();
			if(!S.inSameSet(e.d1 , e.d2))
			{
				S.merge(e.d1 , e.d2);
				printf("%i %i\n", e.d1+1 , e.d2+1);
			}
			H.pop();
		}
	}
 
	return 0;
}  