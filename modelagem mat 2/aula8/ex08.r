#ex 1
x = c(1,2,3)
y = c(4,5,6)
z = c(7,8,9)


A = matrix(c(x,y,z),ncol= 3)
colnames(A) <- c("a","b","c") 

transpA = t(A)
detA = det(A)
inversaA = solve(A)

print(A)
print(transpA)
#matriz determinante de A é nula
print(detA)

print(inversaA)

#ex2 

vet2 = c(0,1,2,3,4,5,6,7,8,9,10,11)

matriz2 = matrix(c(vet2), ncol = 3)
transmatriz2 = t(matriz2)

prod1 = transmatriz2 %*% matriz2
prod2 = matriz2 %*% transmatriz2
detprod1 = det(prod1)
detprod2 = det(prod2)

print(matriz2)
print(transmatriz2)

print(prod1)
print(prod2)

print(detprod1)
print(detprod2)

#ex3 

vX = c(1,1,1,1)
vY = c(1,-1,1,-1)
vZ = c(1,1,-1,0)
vW = c(1,-1,1,0)
vR = c(1,0,2,2)

matriz3 = matrix(c(vX,vY,vZ,vW,vR),ncol = 5)
colnames(matriz3) <- c("X","Y","Z","W","Result")

print(matriz3)


#ex4 

r = sample(0:9,4,replace = TRUE)

print(r)

mex4 = matrix(r, nrow = 2, byrow = TRUE)

print(mex4)

#ex5 


r2 = sample(0:9,9,replace = TRUE)

print(r2)

mex5 = matrix(r, nrow = 3,ncol = 3, byrow = TRUE)

print(mex5)

detmex5 = det(mex5)

detmex5

solvemex5 = solve(mex5)

solvemex5