# Estação Didática Automatizada Controlada por Arduino

## Video

[![Alt text](https://img.youtube.com/vi/upOcH8F2Osk/0.jpg)](https://www.youtube.com/watch?v=upOcH8F2Osk)

## Resumo do projeto

Sistemas automatizados representam a grande maioria dos processos industriais e crescem em ritmo acelerado em todos os setores da sociedade, assim como a o desenvolvimento de software de modo geral, praticamente onipresente no cotidiano comum. Dada a importância da automação, a formação de profissionais altamente capacitados para trabalhar nesses ambientes se tornou meta em vários países.<br/>
Uma estratégia de ensino mais eficiente e moderna pode ser implementada por meio de uma abordagem que exija mais iniciativa e atividade prática do aluno. Este conceito de "aprender na prática" se torna particularmente importante para estudantes de engenharia, já que os profissionais atuando nessa área serão confrontados com problemas práticos a todo momento. O que torna desenvolvimento de ferramentas que possibilitem a realização de exercícios desta natureza fundamental.<br/>
O objetivo deste trabalho foi projetar e construir uma estação automatizada didática de pequeno porte e baixo custo, em nível software e hardware, utilizando tecnologias de hardware e software open source como a plataforma Arduino (microcontrolador) e o freeRTOS (sistema operacional de tempo real), não tão convencionais em meio acadêmico.<br/>
Os resultados obtidos a partir da construção do protótipo totalmente funcional e de duas camadas de software, firmware e interface gráfica, mostram que o uso dessas tecnologias possuem um grande potencial para o desenvolvimento de dispositivos didáticos de baixo custo, relacionados ao ensino de programação, automação de sistemas e software embarcado, contribuindo assim para a democratização do conhecimento em tais áreas.<br/> 

## Code Station

A interface de usuário, chamada de Code Station, foi desenvolvida utilizando a linguagem JavaScript e o framework Electron que permite a construção de aplicações desktop nativas (MacOS, Windows e Linux) utilizando tecnologias de desenvolvimento web como JavaScript, HTML e CSS.<br/> 
A funcionalidade desta interface é permitir com que o usuário desenvolva apenas um algoritmo de controle sem que haja a necessidade em se preocupar com configurações, calibragem, threads e sem que seja preciso utilizar qualquer tipo de conhecimento avançado na linguagem de programação c++, além disso a interface ainda exibe todas as informações necessárias (funções e parâmetros), para que seja feito o controle da estação, sobre cada dispositivo disponível no projeto. 
Para gerar um código que possa ser executado na estação automatizada basta que o usuário escreva um algoritmo utilizando as funções disponíveis dos dispositivos e clique em salvar, fazendo isso o software Code Station insere no código do usuário todas as bibliotecas e configurações necessárias para que tudo seja executado de forma paralela em um RTOS (Real Time Operating System) instalado no microcontrolador da estação, gerando um arquivo final com extensão .ino, que pode ser carregado para o Arduino (microcontrolador) que controla a estação, utilizando a IDE Arduino. 

## Firmware

A camada de software do projeto que tem funções semelhantes às de um firmware em sistemas embarcados, é composta por dois tipos de elementos: 

### Bibliotecas individuais para cada dispositivo da estação 

Para cada dispositivo que pode ser controlado na estação (atuadores e sensores) foi desenvolvida uma biblioteca (utilizando a linguagem c++) própria que tem como funções: configurar e calibrar cada dispositivo de forma automática (sem que o usuário final precise faze-lo) e abstrair as funções de controle e leitura de dados, de forma que o usuário final possa desenvolver um algoritmo que faça todo o controle da estação utilizando apenas estruturas básicas da linguagem C (condicionais, loops, variáveis simples) e as funções de controle e leitura disponíveis nas bibliotecas.<br/>
As bibliotecas são divididas em atuadores e sensores:<br/> 

* Atuadores
    * Esteira
    * Atuadores lineares DC
    * Atuador linear de passo (carimbo)
    * Atuador circular (reservatório giratório)
    * Display LCD

* Sensores
    * Sensor de barreira
    * Sensor de cor
    * Sensor "switch" (fazem parte dos atuadores)
    * Sensor ultrassônico

### Sistema operacional de tempo real (RTOS) 

O sistema operacional de tempo real escolhido para o projeto foi o freeRTOS já que este RTOS é projetado para ser utilizado em microcontroladores, exigindo pouca memória do sistema para funcionar, além disso o software possui licença open source. 
O uso de um RTOS foi necessário para o projeto já que o sistema precisa executar uma série de tarefas de forma paralela para que o usuário final possa escrever um algoritmo de forma simples e estruturada. Tal arquitetura foi alcançada utilizando o recurso de 'multitasking' controlado pelo RTOS.<br/>
O sistema possui 6 threads sendo executadas de forma "simultânea".<br/> 
Vale ressaltar aqui que não é possível executar threads de forma realmente paralela utilizando um Arduino, já que o processador do dispositivo possui apenas um núcleo físico, dessa forma o RTOS "simula" o efeito multitasking via software, utilizando um contexto privado dedicado de RAM e um processo de "scheduling" para executar cada tarefa.<br/> 
As threads utilizadas para o controle da estação são:<br/>

* TaskSensorMonitoring 
* TaskUltrasonicSensorMonitoring
* TaskActuatorControl
* TaskConveyorBeltControl
* TaskStationControl
* TaskDisplayLCD


## License
MIT © [Lucas Grippa](https://github.com/lucas-grippa)
