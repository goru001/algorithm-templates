	ll bsearch(ll low, ll high)
	{

		if (low >= high) {
		   return low;
		}

		ll mid = low + (high-low)/2;

		bool condition =           			//test for set of 2 elements, no yes! if wrong, change mid

		condition ? low = mid : high = mid-1 ;          // maintain the invariant [low,high)
								// other case, low = mid+1 : high = mid , invariant is (low,high]
		return bsearch(low,high);
	}
