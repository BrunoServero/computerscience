M = matrix(data = 1:9,nrow = 3,ncol =3)

print(M)

M2 = matrix(data = 1:9,nrow = 3,ncol = 3, byrow = TRUE)

print(M2)

V3 = c(12,23,34,45,56,67)

M3 = matrix(data = V3, nrow = 3)

print(M3)

M4 = matrix(data = 0, nrow=3, ncol = 5)

print(M4)

M5 = matrix(nrow = 4,ncol = 5)

print(M5)

#matriz para calculos

M6 = matrix(c(2,3,5,6), nrow = 2)
M7 = matrix(c(5,3,8,2), nrow = 2)
M8 = matrix(c(2,4,6,2,0,1),nrow = 2, ncol = 3)
M9 = matrix(c(1,0.5,0.3,0.5,1,0.9,0.3,0.9,1), nrow = 3, ncol = 3)

#soma

m_soma = M7 + M6

print(m_soma)

#subt

m_subt = M7 - M6

print(m_subt)

#MUlt

m_prod_escalar = 42 * M9

print(m_prod_escalar)




