class SDES:
    def __init__(self):
        self.__P10 = [ 3, 5, 2, 7, 4, 10, 1, 9, 8, 6 ]
        self.__P8 = [ 6, 3, 7, 4, 8, 5, 10, 9 ]
        self.__P4 = [ 2, 4, 3, 1 ]
        
        self.__IP = [ 2, 6, 3, 1, 4, 8, 5, 7 ]
        self.__IPi = [ 4, 1, 3, 5, 7, 2, 8, 6 ]

        self.__EP = [ 4, 1, 2, 3, 2, 3, 4, 1 ]

        self.__S0 = [ [ 1, 0, 3, 2 ],
            [ 3, 2, 1, 0 ],
            [ 0, 2, 1, 3 ],
            [ 3, 1, 3, 2 ] ]

        self.__S1 = [ [ 0, 1, 2, 3 ],
            [ 2, 0, 1, 3 ],
            [ 3, 0, 1, 0 ],
            [ 2, 1, 0, 3 ] ]

    def __ls_1(self,arg):
        return arg[1:]+arg[:1]
    
    def __ls_2(self,arg):
        return arg[2:]+arg[:2]

    def __generate_keys(self,k):
        kp = self.__permutate(k,self.__P10)
        
        k1_left = kp[:5]
        k1_right = kp[5:]
        k1_left = self.__ls_1(k1_left)
        k1_right = self.__ls_1(k1_right)
        self.__k1 = self.__permutate(k1_left+k1_right,self.__P8)

        k2_left = self.__ls_2(k1_left)
        k2_right = self.__ls_2(k1_right)
        self.__k2 = self.__permutate(k2_left+k2_right,self.__P8)

    def __list_xor(self,arg1,arg2):
        aux = []
        for i in range(0,len(arg1)):
            if(arg1[i] != arg2[i]):
                aux.append('1')
            else:
                aux.append('0')
        return aux

    def __sb(self,arg,S):
        row = int(arg[0] + arg[3],2)
        column = int(arg[1] + arg[2],2)
        result = S[row][column]
        aux = []
        for _ in range(0,2):
            aux.append(str(result%2))
        return aux

    def __permutate(self,arg,P):
        aux = []
        for i in P:
            aux.append(arg[i-1])
        return aux

    def __Fk(self,ip,k):
        ep = self.__permutate(ip,self.__EP)
        xor_k = self.__list_xor(ep,k)
        concatenated = self.__sb(xor_k[:4],self.__S0)+self.__sb(xor_k[4:],self.__S1)
        p4 = self.__permutate(concatenated,self.__P4)
        return p4

    def __fk(self,ip,k):
        outFk = self.__Fk(ip[4:],k)
        return self.__list_xor(outFk,ip[:4])+ip[4:]
    
    def encrypt_byte(self,cipher,key):
        self.__generate_keys(key)
        ip = self.__permutate(cipher,self.__IP)
        stage_one = self.__fk(ip,self.__k1)
        switch = stage_one[4:]+stage_one[:4]
        stage_two = self.__fk(switch,self.__k2)
        ipi = self.__permutate(stage_two,self.__IPi)
        return ipi

    def decrypt_byte(self,cipher,key):
        self.__generate_keys(key)
        ip = self.__permutate(cipher,self.__IP)
        stage_one = self.__fk(ip,self.__k2)
        swtich = stage_one[4:]+stage_one[:4]
        stage_two = self.__fk(swtich,self.__k1)
        ipi = self.__permutate(stage_two,self.__IPi)
        return ipi