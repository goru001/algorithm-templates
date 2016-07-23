	//suffix-array starts
	struct node{
		int sortindex[2];
		int index;
	};
	int n,step;
	map<int,int> smap;
	vector<int> sarr;	//suffix-array
	vector< vector<int> > rem(20);
	bool cmp( node& a, node& b)
	{
		return a.sortindex[0] == b.sortindex[0] ? ( a.sortindex[1] < b.sortindex[1] ? 1 : 0 ) : ( a.sortindex[0] < b.sortindex[0] ? 1 : 0 ) ;
	}

	void suffix(string s)	//call suffix(string)
	{
		n = s.length();
		sarr.reserve(n);
		for (int i = 0; i < 20; i++)
		{
			rem[i].reserve(n);
		}

		node sa[n];
		step=1;
		int count=1;
		for( int i = 0; i < n; i++)
		{
			rem[0][i] = s[i] - 'a';
		}

		for( ; count>>1 < n ; step++,count<<=1 )
		{
			for(int i=0 ; i<n ; i++)
			{
				sa[i].sortindex[0] = rem[step-1][i];
				sa[i].sortindex[1] = i+count < n ? rem[step-1][i+count] : -1;
				sa[i].index = i;
			}
			sort(sa, sa+n, cmp);
			for(int i=0; i<n; i++)
			{
				rem[step][sa[i].index] = (i>0 && sa[i-1].sortindex[0]==sa[i].sortindex[0] && sa[i-1].sortindex[1]==sa[i].sortindex[1]) ? rem[step][sa[i-1].index] : i;
			}
		}

		for (int  i = 0;  i < n;  i++) {
			smap[rem[step-1][i]]=i;
		}

		int j=0;
		for(auto& i : smap){
		  sarr[j++] = i.second;
		}

	}


	int lcp(int x, int y)		//length of lcp of suffixes starting at x and y
	{
		int k, ans=0;		// lcp(x,y) = min[lcp(x,x+1),lcp(x+1,x+2),lcp(x+2,x+3),....,lcp(y-1,y)]

		if (x==y) {				// so, use rmq if there are too many queries
			return n-x;
		}

		for(k=step-1; k>=0 && x<n && y<n; k--)
		{
			if (rem[k][x] == rem[k][y]) {
				x += 1<<k;
				y += 1<<k;
				ans+= 1<<k;
			}
		}

		return ans;
	}
	//suffix array ends
