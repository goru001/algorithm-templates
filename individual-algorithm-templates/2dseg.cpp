	#define N 1000
	#define M 1000

	int t[4*N][4*M] = {0} ;								// tree
	int a[N][M] = {0};								// n*m matrix
	int n,m;


	void buildy(int idx, int lx, int rx, int idy=1, int ly=0, int ry=m-1)		// id starts from 1
	{										// [ly,ry]

		if ( ly == ry )
		{
			if ( lx == rx)
			{
				t[idx][idy] = a[lx][ly] ;
			}
			else
			{
				t[idx][idy] = t[2*idx][idy] + t[2*idx+1][idy] ;
			}
		}
		else
		{
			int my = ly + (ry - ly)/2 ;
			buildy( idx, lx, rx, 2*idy, ly, my ) ;
			buildy( idx, lx, rx, 2*idy+1, my+1, ry ) ;
			t[idx][idy] = t[idx][2*idy] + t[idx][2*idy+1] ;
		}

	}

	void buildx(int idx=1, int lx=0, int rx=n-1)		// id starts from 1
	{							// call buildx(), [l,r]
		if ( lx != rx )
		{
			int mx = lx + ( rx - lx )/2 ;
			buildx( 2*idx, lx, mx ) ;				// [lx,mx] , left child
			buildx( 2*idx+1, mx+1, rx ) ;				// [mx+1,rx] , right child
		}
		buildy( idx, lx, rx, 1, 0, m-1 ) ;
	}


	ll queryy(int idx, int idy , int tly , int tryy , int ly, int ry)
	{
		if ( ly > ry || ly > tryy || ry < tly )			// no overlap
		{
			return 0;
		}
		if ( ly <= tly && tryy <= ry )				// complete overlap
		{
			return t[idx][idy] ;
		}

		int tmy = tly + (tryy-tly)/2 ;
		return queryy(idx, 2*idy, tly, tmy, ly, min(tmy,ry) ) + queryy(idx, 2*idy+1, tmy+1, tryy, max(ly,tmy+1), ry ) ;
	}

	ll queryx( int lx, int rx, int ly, int ry , int idx=1 , int tlx=0 , int trx=n-1  )	// query in rectangle (lx,ly) to (rx,ry)
	{											// call queryx(x1,x2,y1,y2) where (x1,y1)=upper-left,(x2,y2)=lower-right cood.
		if ( lx > rx || lx > trx || rx < tlx )		// no overlap
		{
			return 0;
		}
	
		if ( lx <= tlx && trx <= rx )			// complete overlap
		{
			return queryy(idx, 1, 0, m-1, ly, ry) ;
		}
	
		int tmx = tlx + (trx-tlx)/2 ;
		return queryx( lx, min(rx,tmx), ly, ry, 2*idx, tlx, tmx ) + queryx( max(lx,tmx+1), rx, ly, ry, 2*idx+1, tmx+1, trx ) ;
	
	}

	void updatey( int x, int y, int value, int idx, int lx, int rx, int idy=1, int ly=0, int ry=m-1 )
	{
		if ( ly == ry )
		{
			if ( lx == rx )
			{
				t[idx][idy] = value ;
			}
			else
			{
				t[idx][idy] = t[2*idx][idy] + t[2*idx+1][idy] ;
			}
		}
		else
		{
			int my = ly + (ry - ly)/2 ;
			if ( y <= my )
			{
				updatey( x, y, value, idx, lx, rx, 2*idy, ly, my ) ;
			}
			else
			{
				updatey( x, y, value, idx, lx, rx, 2*idy+1, my+1, ry ) ;
			}
	
			t[idx][idy] = t[idx][2*idy] + t[idx][2*idy+1] ;
		}

	}

	void updatex(int x, int y, int value, int idx=1, int lx=0, int rx=n-1)		// call updatex(x,y,value) if a[x][y] changes to value.
	{
		if ( lx != rx )
		{
			int mx = lx + (rx-lx)/2 ;
			if ( x <= mx )
			{
				updatex( x, y, value, 2*idx, lx, mx ) ;
			}
			else
			{
				updatex( x, y, value, 2*idx+1, mx+1, rx ) ;
			}
		}
	
		updatey( x, y, value, idx, lx, rx, 1, 0, m-1 ) ;
	}
	// assign values to n( no. of rows ), m( no. of columns ), array a! And then call build!
