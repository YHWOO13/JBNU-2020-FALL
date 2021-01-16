library(klaR)
library(MASS)

y=UScrime$y
hist(y, breaks= 4)
#같은 간격의 범주화
UScrime=within(UScrime, {binning=character(0)
binning[UScrime$y<500]=1
binning[UScrime$y>=500 & UScrime$y<1000]=2
binning[UScrime$y>=1000 & UScrime$y<1500]=3
binning[UScrime$y>=1500 & UScrime$y<2000]=4
binning=factor(binning, level=c(1,2,3,4))
})

U1=UScrime$U1
hist(U1,breaks=5)
UScrime=within(UScrime, {binning1=character(0)
binning1[UScrime$U1<80]=1
binning1[UScrime$U1>=80 & UScrime$U1<100]=2
binning1[UScrime$U1>=100 & UScrime$U1<120]=3
binning1[UScrime$U1>=120 & UScrime$U1<140]=4
binning1[UScrime$U1>=140 & UScrime$U1<160]=5
binning1=factor(binning1, level=c(1,2,3,4,5))
})

U2=UScrime$U2
hist(U2,breaks=4)
UScrime=within(UScrime, {binning2=character(0)
binning2[UScrime$U2<30]=1
binning2[UScrime$U2>=30 & UScrime$U2<40]=2
binning2[UScrime$U2>=40 & UScrime$U2<50]=3
binning2[UScrime$U2>=50 & UScrime$U2<60]=4
binning2=factor(binning2, level=c(1,2,3,4))
})

Ineq=UScrime$Ineq
hist(Ineq,breaks=4)
UScrime=within(UScrime, {binning3=character(0)
binning3[UScrime$Ineq<150]=1
binning3[UScrime$Ineq>=150 & UScrime$Ineq<200]=2
binning3[UScrime$Ineq>=200 & UScrime$Ineq<250]=3
binning3[UScrime$Ineq>=250 & UScrime$Ineq<300]=4
binning3=factor(binning3, level=c(1,2,3,4))
})

Ed=UScrime$Ed
hist(Ed,breaks=4)
UScrime=within(UScrime, {binning6=character(0)
binning6[UScrime$Ed<90]=1
binning6[UScrime$Ed>=90 & UScrime$Ed<100]=2
binning6[UScrime$Ed>=100 & UScrime$Ed<110]=3
binning6[UScrime$Ed>=110 & UScrime$Ed<120]=4
binning6[UScrime$Ed>=120 & UScrime$Ed<130]=5
binning6=factor(binning6, level=c(1,2,3,4,5))
})

#데이터 셋 전처리
UScrime=UScrime[,c(9,7,18,19,20,21,17)]
names(UScrime)=c("NW","M.F","U1","U2","Ineq","Ed","binning")
head(UScrime)

#70%의 train data를 지정한다.
set.seed(47)
train_data=sample(1:47,33)
test_data=-train_data

#단순 베이즈 모델
violence_Crime=NaiveBayes(binning~., data=UScrime, subset=train_data)

#모델 정확도
table=table(UScrime$binning[test_data], predict(violence_Crime,UScrime[test_data,])$class)
table
classification_ratio=sum(table[row(table)==col(table)])/sum(table)
mis_classification_ratio=1-classification_ratio
classification_ratio
mis_classification_ratio
