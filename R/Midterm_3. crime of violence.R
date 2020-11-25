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
# 데이터셋 가공
UScrime=UScrime[,c(3,7,9,10,11,13,17)]
head(UScrime)

#70%의 train data를 지정한다.
set.seed(47)
train_data=sample(1:47,33)
test_data=-train_data
#단순 베이즈 모델
violence_Crime=NaiveBayes(binning~., data=UScrime, subset=train_data)
violence_Crime
#모델 정확도
table=table(UScrime$binning[test_data], predict(violence_Crime,UScrime[test_data,])$class)
table
classification_ratio=sum(table[row(table)==col(table)])/sum(table)
mis_classification_ratio=1-classification_ratio
classification_ratio
mis_classification_ratio
