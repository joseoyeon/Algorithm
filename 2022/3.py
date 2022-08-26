class sol :
    def __init__(self) :
        self.visit = []

    def setdata(self, visit) : 
        self.visit = visit
    
    def solved(self) :
        self.visit.sort()
    
        for i in range(len(self.visit)) :
            if ((self.visit[i] <= len(self.visit) - i) and (self.visit[i] >= i) ) :
                answer = self.visit[i]

        return answer


def main() :
    visit = list(map(int , input().strip('['']').split(sep=',')))
    sol_ = sol()
    sol_.__init__()
    sol_.setdata(visit)
    print(sol_.solved())

if __name__ == "__main__" : 
    main()
