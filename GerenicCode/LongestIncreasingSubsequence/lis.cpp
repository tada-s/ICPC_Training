int lis(int v[]){
    vector<int> headIndex;
    vector<int> parentIndex;

    headIndex.pb(0);
    parentIndex.pb(-1);
    for(int i = 1; i < n; i++){
        int lb = 0;
        int ub = headIndex.size() - 1;
        int key = v[i];
        while(lb <= ub){
            int mid = (lb + ub) / 2;
            int value = v[headIndex[mid]];
            if(value < key){
                lb = mid + 1;
            }else{
                ub = mid - 1;
            }
        }
        int bestIndex = ub;
        if(bestIndex + 1 == headIndex.size()){
            headIndex.pb(i);
        }else{
            if(v[i] < v[headIndex[bestIndex + 1]]){
                headIndex[bestIndex + 1] = i;
            }
        }
        if(bestIndex == -1){
            parentIndex.pb(-1);
        }else{
            parentIndex.pb(headIndex[bestIndex]);
        }
	}
	return headIndex.size();
}
