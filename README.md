# 基于Qt的图像识别项目

## 主要模块：

### 	multimedia

### 	multimediawidgets

### 	network

## 主要功能：

### 	1、下拉列表切换可调用摄像头

### 	2、实现人脸追踪，并使用红色框标注

### 	3、使用人脸识别技术分析并展示人脸属性，包含如下：

#### 		 1）年龄

#### 		 2）性别

#### 		 3）情绪

#### 		 4）颜值

#### 		 5）是否戴口罩

####  		6）是否戴眼镜

#### 		 7）真人的可能性

## 主要技术：

### 	1、使用QNetworkAccessManager发起网络请求，通过ssl1.1.1解决Qt无法通过	      https的问题

### 	2、使用百度智能云API分析人脸数据

#### 		 AI接入指南：[通用参考 - AI接入指南 | 百度AI开放平台 (baidu.com)](https://ai.baidu.com/ai-doc/REFERENCE/Ck3dwjgn3)

#### 		 温馨提示：Access Token的有效期为30天（以秒为单位），请您集成时注意在程序中定期请求新的				    token。

### 	3、线程池实现Base64编码转码，防止主线程无响应，并实现更高频率刷新人脸识别

### 	4、解析JSON文本参数，获取服务器返回的参数