library(DMwR)
library(neuralnet)
library(party)
library(rpart)
# Read Data ---------------------------------------------------------------
setwd("C:\\Users\\syjy0\\OneDrive\\바탕 화면\\European Soccer Database")
player_Attributes=read.csv("player_attributes.csv",header=TRUE)
player=read.csv("player.csv",header=TRUE)
name_birth=read.csv("name_birth.csv",header=TRUE)
name_position=read.csv("name_position.csv",header=TRUE)

# Data Collection ------------------------------------------------------
colnames(name_birth)=c("player_name","birthday")
colnames(name_position)=c("player_name","position")
#선수이름 대입
MANU=merge(player,player_Attributes, by='player_api_id', all=TRUE)
# 이름이 겹치는 경우도 있고, 생일이 겹치는 경우도 있기때문에
# name_birth와 name_position 두 개의 데이터셋으로 두번 교집합 한다.
MANU=merge(MANU,name_birth, by='birthday',all=FALSE)

# Data Preprocessing ------------------------------------------------------
# x축 y축 이름 속성이 2개개 생기는데 x축 이름속성이 원하는 데이터이므로 X축만 남긴다.
MANU=MANU[,-c(49)]
colnames(MANU)[4]="player_name"
MANU=merge(MANU,name_position, by='player_name',all=FALSE)
MANU[,c(3,49)]= MANU[,c(49,3)]
View(MANU_Complete)
colnames(MANU)[3]="Position"
colnames(MANU)[49]="player_api_id"
#두 데이터를 합치며 생긴 중복된 속성들 삭제
#데이터 분석하는데 필요하지 않다고 판단되 속성들 삭제
MANU=MANU[,-c(2,4,5,6,7,8,9,49)]
# 각 선수별 한 시즌의의 데이터만 남기기 위해 csv파일에서 수작업
write.csv(MANU,file="MANU.csv")

#마지막 전처리(수작업)를 끝낸 데이터 불러오기
MANU_Complete=read.csv("MANU_Complete.csv",header=TRUE)
MANU_Complete=MANU_Complete[,-c(1,4,7)]
# "Edwin van de sar","Gary Neville"
#  위 두 선수의 공격,수비 참여도 결측값 해결
MANU_Complete[28, 5]="medium"
MANU_Complete[28, 6]="medium"
MANU_Complete[36, 5]="medium"
MANU_Complete[36, 6]="high"

#공격, 수비 참여도 low=1, medium=2, high=3
MANU_Complete=within(MANU_Complete, {Attaking_rate=integer(0)
Attaking_rate[MANU_Complete$attacking_work_rate=="low"]=1
Attaking_rate[MANU_Complete$attacking_work_rate=="medium"]=2
Attaking_rate[MANU_Complete$attacking_work_rate=="high"]=3})

MANU_Complete=within(MANU_Complete, {Defense_rate=integer(0)
Defense_rate[MANU_Complete$defensive_work_rate=="low"]=1
Defense_rate[MANU_Complete$defensive_work_rate=="medium"]=2
Defense_rate[MANU_Complete$defensive_work_rate=="high"]=3})

MANU_Complete[,c(5,6,40,41)]=MANU_Complete[,c(40,41,5,6)]
MANU_Complete=MANU_Complete[,-c(40,41)]
#원활한 데이터 분석을 위해 선수 이름을 빼준다.
MANU_NONPLAYER=MANU_Complete[,-1]
MANU_NONPLAYER$Position=factor(MANU_NONPLAYER$Position)

# Data Explanation --------------------------------------------------------
GK=subset(MANU_Complete, Position=="GK")
DF=subset(MANU_Complete, Position=="DF")
MF=subset(MANU_Complete, Position=="MF")
FW=subset(MANU_Complete, Position=="FW")

GK=GK[,-c(1,2)]
GK=GK[,c(1,3,4,33:37)]
colMeans(GK)

FW=FW[,-c(1,2)]
FW=FW[,c(1,3,4,6,14,16,19,20)]
colMeans(FW)

MF=MF[,-c(1,2)]
MF=MF[,c(1,3,4,5,8,10,13,22)]
colMeans(MF)

DF=DF[,-c(1,2)]
DF=DF[,c(1,3,4,23,26,30,31,32)]
colMeans(DF)
# DATA ANALYSIS -----------------------------------------------------------
set.seed(100)
ind=sample(1:nrow(MANU_NONPLAYER), as.integer(0.7*nrow(MANU_NONPLAYER)))
Train=MANU_NONPLAYER[ind,]
Test=MANU_NONPLAYER[-ind,]

# Decision Tree -----------------------------------------------------------
MANU_tree=rpart(Position~gk_reflexes+dribbling+finishing+standing_tackle+stamina,data=MANU_NONPLAYER)
Train_tree=ctree(Position~gk_reflexes+dribbling+finishing+standing_tackle+stamina,data=Train)
Test_tree=ctree(Position~gk_reflexes+dribbling+finishing+standing_tackle+stamina,data=Test)
plot(MANU_tree,compress=T,margin=0.3)
text(MANU_tree,cex=1)
#테이블
testpred=predict(Train_tree,newdata=Test)
MANU_TREE_table=table(testpred,Test$Position)
MANU_TREE_table
#정확도
classification_ratio=sum(MANU_TREE_table[row(MANU_TREE_table)==col(MANU_TREE_table)])/sum(MANU_TREE_table)
mis_classification_ratio=1-classification_ratio
classification_ratio
mis_classification_ratio

# k-NN --------------------------------------------------------------------

MANU_KNN=kNN(Position~gk_reflexes+dribbling+finishing+standing_tackle+stamina, Train, Test, norm=FALSE,k=7)
summary(MANU_KNN)
MANU_KNN_table=table(Test[,'Position'],MANU_KNN)
MANU_KNN_table
classification_ratio=sum(MANU_KNN_table[row(MANU_KNN_table)==col(MANU_KNN_table)])/sum(MANU_KNN_table)
mis_classification_ratio=1-classification_ratio
classification_ratio
mis_classification_ratio

# Artificial Neural Network -----------------------------------------------

MANU_net_2=neuralnet(Position~gk_reflexes+dribbling+finishing+standing_tackle+stamina, data=Train, hidden=2, err.fct="ce", linear.output =  FALSE, likelihood=TRUE)
plot(MANU_net_2)
MANU_net_5=neuralnet(Position~gk_reflexes+dribbling+finishing+standing_tackle+stamina, data=Train, hidden=5, err.fct="ce", linear.output =  FALSE, likelihood=TRUE)
plot(MANU_net_5)
MANU_net_7=neuralnet(Position~gk_reflexes+dribbling+finishing+standing_tackle+stamina, data=Train, hidden=7, err.fct="ce", linear.output =  FALSE, likelihood=TRUE)
plot(MANU_net_7)
