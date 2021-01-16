library(MASS)
library(tree)
library(e1071)
library(caret)

# 몇개의 구간으로 나눌지 확인
y=UScrime$y
hist(y, breaks=4)
#같은 간격의 범주화
UScrime=within(UScrime, {binning=character(0)
binning[UScrime$y<500]=1
binning[UScrime$y>=500 & UScrime$y<1000]=2
binning[UScrime$y>=1000 & UScrime$y<1500]=3
binning[UScrime$y>=1500 & UScrime$y<2000]=4
binning=factor(binning, level=c(1,2,3,4))
})
#train & test data 세팅
set.seed(47)
classification=createDataPartition(y=UScrime$y,p=0.7,list=FALSE)
train_data=UScrime[classification,]
test_data=UScrime[-classification,]

violent_crime=tree(binning~Prob+NW+Time+Ed,data=train_data)
plot(violent_crime)
text(violent_crime)

#기준 정하기
criteria_pruning=cv.tree(violent_crime, FUN=prune.misclass)
plot(criteria_pruning)

pruning=prune.misclass(violent_crime, best=3)
plot(pruning)
text(pruning, pretty=0)

treepred=predict(pruning, test_data, type="class")
confusionMatrix(treepred, test_data$binning)
