# Author: Yoonhyuck WOO /JBNU_Industrial Information system Engineering 
# Date  ; Sep. 17 2020
# Title:  Week2: Vector, Matrix, Data Frame

# Manage Vector
v=51:90
#1)
condi=v<60
v[condi]
#2)
sum(v<70)
#3)
sum(v[v>65])
#4 AND
cond1=60<v& v<73
v[cond1]
#5 OR
cond2=65>v | v>80
v[cond2]
#6
cond3=(v%%7==3)
v[cond3]
#7
cond4=(v%%2==0)
v[cond4]
#8
cond5=(v%%2==1)|(v>80)
v[cond5]
#9
cond6=(v%%3==0)&(v%%5==0)
v[cond6]

#Matrix
#1
score=matrix(nrow=4, ncol=2)
#2
male=c(10,40,60,20)
female=c(21,60,70,3)
score=cbind(male,female)
score
#3
score[2,]
#4
score[,2]
#5
score[3,2]

#Data Frame
#1
st=data.frame(state.x77)
#2
st
#3
colnames(st)
#4
rownames(st)
#5 행&열의 개수
dim(st)
#6 데이터 요약
str(st)
#7
rowSums(st)
rowMeans(st)
#8
colSums(st)
colMeans(st)
#9
st["Florida",]
#10
region=rownames(st)
Income=st[,"Income"]
result=cbind(region,Income)
result
#11
st["Texas","Area"]
#12
st["Ohio",c("Population","Income")]
#13
people5000=st[st$Population>=5000,]
region=rownames(people5000)
population=people5000[,"Population"]
result=cbind(region,population)
result=data.frame(result)
result
#14
income4500=st[st$Income>=4500,]
region=rownames(income4500)
income=income4500[,"Income"]
population=income4500[,"Population"]
area=income4500[,"Area"]
r1=cbind(region,income)
r2=cbind(population,area)
r=cbind(r1,r2)
df=data.frame(r)
df
#15
sum(income>4500)
#16 usefulness of subset
condi1=subset(st,Frost>=120&Area>100000)
condi1=subset(condi1,select=c(Frost,Area))
condi1
#17
nrow(condi1)
#18
result=subset(st,Illiteracy>=2.0&Income)
result=subset(result,select=c(Illiteracy,Income))
means=colMeans(result)
means
#19
result2=subset(st,Illiteracy<2.0&Income)
result2=subset(result2,select=c(Illiteracy,Income))
means2=colMeans(result2)
means2
result3=means-means2
result3
#20
region=rownames(st)
life=st[,"Life.Exp"]
result=cbind(region,life)
df=data.frame(result)
max=which.max(df$life)
df[max,]
#21
region=rownames(st)
income=st[,"Income"]
criteria=cbind(region,Income)
criteria=data.frame(criteria)
norm=criteria[region=="Pennsylvania",]
norm=norm[1,2]
result=subset(criteria,Income>norm)
result

#Load file
last=st[st$Income>5000,]
write.csv(last,file="rich_stat.csv")
ds=read.csv("rich_stat.csv",header=TRUE)
ds