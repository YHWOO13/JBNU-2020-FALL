library(MASS)
library(kknn)
library(caret)
library(DMwR)

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
UScrime=UScrime[,c(1,10,11,8,17)]
head(UScrime)

#train & test 데이터 셋
set.seed(47)
criteria=createDataPartition(y=UScrime$binning, p=0.7, list=FALSE)
train_data=UScrime[criteria,]
test_data=UScrime[-criteria,]

UScrime.kknn=kknn(binning~., train_data, test_data,distance=1, kernel="triangular")
summary(UScrime.kknn)

fit=fitted(UScrime.kknn)
table=table(test_data$binning, fit)
table
classification_ratio=sum(table[row(table)==col(table)])/sum(table)
mis_classification_ratio=1-classification_ratio
classification_ratio
mis_classification_ratio

#산점도 그래프
pcol=as.character(as.numeric(test_data$binning))
pairs(test_data[1:4], main="Traffic crime", pch=pcol, col=c("green3","red")[(test_data$binning !=fit)])
