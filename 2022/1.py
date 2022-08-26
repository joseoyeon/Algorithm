class sol :
    def __init__(self) :
        self.star = 10
        self.rec= 8
    
    def setdata(self, star, rec) :
        self.star = star
        self.rec = rec

    def solved(self) :
        for i in range(self.star):
            #첫번째 삼각형
            for j in range(self.star-i) :
                print("*", end="")
            for j in range(i*2) : 
                print(" ", end="")
            
            # 거꾸로된 피라미드
            for j in range(self.star*2,i*2+2,-1) : 
                print('*', end="")
            for j in range(i) : 
                print(" ", end="")
        
            # 일직선
            print(" ", end="")
            for j in range(self.rec):
                print("*", end="")
            print("")


        for i in range(2,self.star+1) : 
            for j in range(i) :
                print("*", end="")    
            for j in range((self.star-i)*2):
                print(' ', end="")

            for j in range(1,i*2-1,1):
                print("*", end="")
            for j in range(self.star-i) : 
                print(" ", end="")
            
            
            print(" ", end="")
            for j in range(self.rec):
                print("*", end="")
            print("")

def main():
    sol_ = sol()
    sol_.__init__()
    sol_.setdata(10,8)
    sol_.solved()

if __name__ == "__main__":
	main()
