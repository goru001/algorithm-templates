	map< ll,ll > parent; 		// reserve space for map if n > 10000
	map< ll,ll > urank;

	void create(ll x)
	{
		parent[x] = x ;
		urank[x] = 0 ; 		// rank = no. of nodes in its subtree
	}

	ll find(ll x)
	{
		if( parent[x] != x )	//path compression
		{
			parent[x] = find(parent[x]) ;
		}
		return parent[x];
	}

	void merge(ll x, ll y)
	{
		ll xroot = find(x);
		ll yroot = find(y);

		if( urank[xroot] <= urank[yroot] )	// Union by rank
		{
			parent[xroot] = yroot ;
			urank[yroot] = urank[yroot] + urank[xroot] ;
		}
		else
		{
			parent[yroot] = xroot;
			urank[xroot] = urank[xroot] + urank[yroot] ;
		}
	}
