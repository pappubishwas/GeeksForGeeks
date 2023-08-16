        int r=0,sum=1;
        while(n>=sum){
            n=n-sum;
            sum=sum+1;
            r++;
        }
        return r;