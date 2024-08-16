- Quando o entrevistador fizer a pergunta, anote os pontos-chave no topo (ou seja, sorted array). Certifique-se de ter todos os detalhes. Mostre como você é organizado.
- Certifique-se de verificar novamente: Quais são as entradas? Quais são as saídas?
- Qual é o valor mais importante do problema? Você tem tempo, espaço e memória etc. Qual é o objetivo principal?
- Não seja chato e faça muitas perguntas.
- Comece com a abordagem ingênua/força bruta. Primeira coisa que vem em mente. Isso mostra que você é capaz de pensar bem e criticamente (você não precisa escrever este código, apenas falar sobre ele).
- Diga-lhes porque esta abordagem não é a melhor (ou seja, O(n^2) ou superior, não legível, etc...)
- Percorra sua abordagem, comente as coisas e veja onde você pode quebrar as coisas. Alguma repetição, gargalos como O(N^2) ou trabalho desnecessário? Você usou todas as informações o entrevistador te deu?
- Antes de começar a codificar, percorra seu código e anote as etapas que você seguirá
- Modularize seu código desde o início. Divida seu código em belos pedaços pequenos e adicione apenas comentários, se necessário.
- Comece realmente a escrever seu código agora. Tenha em mente que quanto mais você se preparar e entender o que você precisa codificar, melhor será o whiteboard. Portanto, nunca inicie um whiteboard na entrevista sem ter certeza de como as coisas vão funcionar. Essa é uma receita para o desastre. Lembre-se: muitas entrevistas fazem perguntas que você não conseguirá responder completamente a tempo. Então pense: O que eu posso mostrar para mostrar que eu posso fazer isso e sou melhor que os outros devs. Divida as coisas em Funções (se você não consegue se lembrar de um método, apenas crie uma função e você vai pelo menos tê-lo lá. Escreva algo e comece com a parte fácil.
- Pense nas verificações de erros e em como você pode quebrar esse código. Nunca faça suposições sobre entrada. Suponha que as pessoas estão tentando quebrar seu código e que Darth Vader está usando sua função. Como você vai protegê-lo? Sempre verifique se há entradas falsas que você não deseja. Aqui está um truque: Comente no código, as verificações que você quer fazer... escreva a função, depois diga ao entrevistador que você escreveria testes agora para fazer sua função falhar (mas você não precisará realmente escrever os testes).
- Não use nomes ruins/confusos como i e j. Escreva um código que leia bem.
- Teste seu código: verifique se não há parâmetros, 0, undefined, nul, arrays massivos, código assíncrono, etc… Pergunte ao entrevistador se pudermos fazer suposições sobre o código. Você pode fazer a resposta retornar um erro? Faça furos em sua solução. Você está se repetindo?
- Por fim, fale com o entrevistador onde você melhoraria o código. Funciona? Existem abordagens diferentes? É legível? O que você buscaria no Google para melhorar? Como o desempenho pode ser melhorado? Possivelmente: Pergunte ao entrevistador qual foi a mais interessante solução que você viu para este problema.
- Se o seu entrevistador estiver satisfeito com a solução, a entrevista geralmente termina aqui. Também é comum que o entrevistador faça perguntas de extensão, como como você lidaria com o problema se toda a entrada for muito grande para caber na memória ou se a entrada chegar como uma stream. Esta é uma pergunta de acompanhamento comum no Google, onde eles se preocupam muito com a escala. A resposta geralmente é uma abordagem de dividir e conquistar - executa o processamento distribuído dos dados e apenas lê certos pedaços da entrada do disco na memória, grava a saída de volta no disco e  combiná-los mais tarde.