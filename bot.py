import random
def get_move(my,other):
    if(len(my)==0): return 'C'
    elif(other[-1]=='C'): return 'C'
    else:
        if(random.randint(0,10)==0): return 'C'
        else: return 'D'

