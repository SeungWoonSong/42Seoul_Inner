# page 0
  
Ft_services
  
요약: 시스템 관리 및 네트워킹 프로젝트입니다.
  
# page 1

Contents

| Chapter | Contents | Page |
|:---:|:---|:---:|
| I | [__Introduction__]() | 2 |
| II | [__General instructions__]() | 3 |
| III | [__Mandatory part__]() |  4 |
  
# page 2
  
Chapter I
  
Introduction
  
Ft_services는 여러분에게 쿠버네티스(Kubernetes)를 소개할겁니다.  
여러분은 쿠버네티스와 함께 클러스터 관리와 deployment를 발견할겁니다.  
여러분은 네트워크를 가상화하고, "clustering" 하게 될 것 입니다.  

# page 3
  
Chapter II
  
General instructions
  
* 여러분께서는 여러분의 서버 설정에 필요한 필수 파일들을 모두 srcs 폴더에 넣어야 합니다.
* 여러분의 setup.sh 파일은 여러분 repository의 root에 있어야 합니다. 이 스크립트는 여러분의 모든 application을 설정해줄겁니다.
* 이 과제는 옛 관습과 새 관습 모두를 요합니다. 그러므로 여러분들은 도커(Docker)문서, 쿠버네티스 문서, 그 외에 프로젝트에 도움이 될만한 모든 문서들을 읽는 것을 두려워하지 마세요.
  
# page 4
  
Chapter III
  
Mandatory part
  
이 프로젝트는 서로 다른 서비스의 인프라를 설정하는 것으로 구성됩니다.  
이렇게 하려면 여러분은 쿠버네티스를 사용해야만 합니다.  
여러분은 다중-서비스 클러스터를 설정해야만 할겁니다.  
각각의 서비스는 전용 컨테이너 안에서 실행되어야 합니다.  
각 컨테이너는 해당 서비스와 같은 이름을 사용해야하고, 성능상의 이유로 컨테이너는 알파인 리눅스(Alpine Linux)를 사용해 빌드해야합니다.  
또한 setup.sh에서 호출되는 Dockerfile이 작성되어 있어야합니다.  
여러분께서는 여러분이 쓸 이미지를 스스로 만들어야 합니다.  
이미 빌드되어있는 이미지를 사용하거나, 도커허브(DockerHub)와 같은 서비스를 사용하는 것은 금지되어 있습니다.  
  
또한, 여러분들은 다음과 같이 설정해야합니다:  
  
* 쿠버네티스 웹 대쉬보드(Kubernetes web dashboard). 이건 여러분들이 클러스터를 관리하는데 도움이 될겁니다.
  
* 서비스의 외부진입을 관리하는 로드 밸런서(Load Balancer). 이건 여러분의 클러스터에 접속하는 유일한 진입점이 될 겁니다. 서비스와 연결된 포트를 유지해야 합니다.(그라파나(grafana) 등의 경우는 IP:3000)
  
* 80포트와 443포트에서 수신중인 엔진엑스(Nginx)서버. 포트 80은 http로 되어 있으며 https로 되어 있는 타입 301에서 443으로 리디렉션되야 합니다.
  
* 21포트에서 수신중인 FTPS 서버.
  
* MySQL 데이터베이스와 함께 작동하고 5050포트에서 수신중인 워드프레스(WordPress) 웹사이트. 두 서비스는 분리된 컨테이너에서 동작해야합니다. 워드프레스 웹사이트는 여러 유저와 하나의 관리자를 가질 수 있어야 합니다.
  
* MySQL 데이터베이스와 연결되고 5000포트에서 수신중인 PhpMyAdmin.
  
* InfluxDB 데이터베이스와 연결되고 3000포트에서 수신중인 그라파나(Grafana) 플랫폼. 그라파나는 여러분의 모든 컨테이너를 모니터링 할겁니다. 여러분은 서비스 하나당 하나의 대쉬보드를 만들어야 합니다. InfluxDB와 그라파나는 서로 다른 두 개의 컨테이너 안에 있어야 합니다.
  
* 두 개의 데이터베이스 컨테이너 중 하나가 멈추거나 충돌하는 경우에는, 데이터가 지속되는지 확인해야 합니다.
  
# page 5
  
* 여러분은 엔진엑스(Nginx) 컨테이너에 SSH로 접근 가능하게 해야합니다.
  
* 구성 요소 중 하나가 충돌하거나 중지되는 경우 모든 컨테이너를 다시 시작해야 합니다.
  
:exclamation: 노드 포트 서비스, Ingress Controller object 또는 kubectl port-forward의 사용은 금지됩니다. 여러분의 클러스터의 유일한 진입점이 로드 밸런서야만 합니다.
  
:bulb: Cloud Provider에서 제공하는 로드 밸런싱을 사용하는것은 아무 도움이 안됩니다. 차라리 MetalLb를 보는 편이 나을겁니다.
  
:bulb: 보안이 중요한건데, 해서는 안 될 서비스를 노출시키지 마세요...
