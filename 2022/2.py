class sol : 
    def __init__(self) : 
        self.n = None
        self.k = None
        self.cash = []
        self.dp = []
    
    def setdata(self, n,k,cash) :
        self.n = n 
        self.k = k 
        self.cash = cash 
        self.dp = [0] * (k+1)
        self.dp[0] = 1

    def solved(self) :
        for c in self.cash :
            for j in range(c,self.k+1) :
                if(j-c >= 0 ) : 
                    self.dp[j] += self.dp[j-c]
        return self.dp[self.k]


def main():
    n,k = map(int,input().split())
    cash = [int(input()) for _ in range(n)] 

    sol_ = sol()
    sol_.__init__()
    sol_.setdata(n,k,cash)
    print(sol_.solved())

if __name__ == "__main__":
	main()

