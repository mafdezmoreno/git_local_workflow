# Git Local Workflow

Se indican los comandos imprescindibles para trabajar con una copia __local__ de un repositorio git.

## Crear un repositorio

Para crear un repositorio vacío se usa el comando:

```git
git init
```

Se creará la carpeta `.git` en el directorio que se ejecute la anterior orden.

```git
$ git init
Initialized empty Git repository in C:/git_workflow_example/.git/
```

## Revisando el estado e historial del repositorio

### __git status__

Comprobación del estado de nuestro repositorio:

```git
git status
```

Indica si el contenido actual del repositorio está modificado con respecto a la última versión registrada (con respecto al último commit).

Si el repositorio está recien inicializado indicará:

```git
$ git status
On branch master

No commits yet

nothing to commit (create/copy files and use "git add" to track)
```

En caso contrario, si hemos realizado cambios, nos indica los ficheros modificados:

```git
$ git status
On branch master

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        .gitignore
        main.cpp

nothing added to commit but untracked files present (use "git add" to track)
```

En este caso, los ficheros modificados son: `.gitignore` y `main.cpp`.

Puedes crear algunos ficheros en el repositorio y comprobar como te devuelve un mensaje similar al anterior.

__Atención__ Para comprobar futuras funcionalidades, puedes crear un par de commits empleando los siguientes comandos (creando y/o modificando un fichero previa ejecución de los mismos):

```git
    git add .
    git commit -m "hola mundo"
```

En cada commit, cambia el mensaje entre comillas con algún comentario que identifique los cambios realizados por el commit. Más adelante entraremos en detalle de estos comandos.

Y ahora, si vuelves a ejecutar `git --status`:

```git
$ git status
On branch master
nothing to commit, working tree clean
```

Nos indica que no existe ningún cambio sin registrar en nuestra copia local.

### __git log__

```git
git log
```

Este comando nos imprime los diferentes commits realizados en nuestro repositorio:

```git
$ git log
commit 2b0fa026b052edffa80b4f55cd36627b164094f3 (HEAD -> master)
Author: usuario <usuario@ejemplo.com>
Date:   Wed Nov 4 11:21:22 2020 +0100

    comprobacion correcta ejecucion programa

commit 623c3dd1733d2370dca2952066dd3578180e66b7
Author: usuario <usuario@ejemplo.com>
Date:   Wed Nov 4 11:19:48 2020 +0100

    hola mundo
```

La información que se imprime para cada commit realizado es la siguiente:

1. SHA: código que identifica inequívocamente el commit.
2. Autor (usuario)
3. La fecha de realización del commit
4. El mensaje incluido con el commit

__Atención__ Si partes de un repositorio de nueva creación, sin ningún commit realizado, en la consola te aparecerá:

```git
$ git log
fatal: your current branch 'master' does not have any commits yet
```

Crea algún commit, como se ha indicado en el anterior apartado, para comprobar lo que nos devuelven los comandos indicados.

### git log --oneline

Para agilizar la navegación entre los diferentes commits, se puede usar el sufijo `--oneline`.

```git
$ git log --oneline
2b0fa02 (HEAD -> master) comprobacion correcta ejecucion programa
623c3dd hola mundo
```

De esta forma es mucho más sencillo seguir la lista de todos los commit realizados y encontrar el commit buscado.

Como se puede comprobar, solo se muestran los 7 primeros caracteres del SHA y el mensaje de cada commit.

### git log --stat

Para obtener más información de cada uno de los commits, se puede añadir el sufijo `--stat`.

```git
$ git log --stat
commit 2b0fa026b052edffa80b4f55cd36627b164094f3 (HEAD -> master)
Author: usuario <usuario@ejemplo.com>
Date:   Wed Nov 4 11:21:22 2020 +0100

    comprobacion correcta ejecucion programa

 main.cpp | 5 ++++-
 1 file changed, 4 insertions(+), 1 deletion(-)

commit 623c3dd1733d2370dca2952066dd3578180e66b7
Author: usuario <usuario@ejemplo.com>
Date:   Wed Nov 4 11:19:48 2020 +0100

    hola mundo

 .gitignore | 3 +++
 main.cpp   | 7 +++++++
 2 files changed, 10 insertions(+)


 ```

 como se puede comprobar en el anterior ejemplo, ahora se muestran:

 1. Los ficheros modificados.
 2. El número de lineas añadidas y/o borradas.

### git log --patch

Este comando, es similar al anterior, pero nos indica más información aún: nos indica las líneas que se ha modificado.

```git
$ git log --patch
commit 2b0fa026b052edffa80b4f55cd36627b164094f3 (HEAD -> master)
Author: usuario <usuario@ejemplo.com>
Date:   Wed Nov 4 11:21:22 2020 +0100

    comprobacion correcta ejecucion programa

diff --git a/main.cpp b/main.cpp
index 0e0deff..6f47fa8 100644
--- a/main.cpp
+++ b/main.cpp
@@ -2,6 +2,9 @@

 int main(){

-    std::cout<< "Hola mundo!"<<std::endl;
+    std::cout<< "\nHola mundo!"<<std::endl;

+    std::cout<< "\nprograma finalizado correctamente\n"<<std::endl;
+
+    return 0;
 }
```

El comando `git log -p` es equivalente a `git log -patch`.


### git log --patch <sha>

para ver solo un commit, se lo podemos indicar a continuación de `--patch` indicando los 7 primeros dígitos del SHA del commit:

```git
git log --patch 623c3dd
```

### __git show__

Este comando es similar a `git log --patch`, pero solo nos muestra por defecto el último commit.

```git
$ git show
commit 2b0fa026b052edffa80b4f55cd36627b164094f3 (HEAD -> master)
Author: usuario <usuario@ejemplo.com>
Date:   Wed Nov 4 11:21:22 2020 +0100

    comprobacion correcta ejecucion programa

diff --git a/main.cpp b/main.cpp
index 0e0deff..6f47fa8 100644
--- a/main.cpp
+++ b/main.cpp
@@ -2,6 +2,9 @@

 int main(){

-    std::cout<< "Hola mundo!"<<std::endl;
+    std::cout<< "\nHola mundo!"<<std::endl;

+    std::cout<< "\nprograma finalizado correctamente\n"<<std::endl;
+
+    return 0;
 }
\ No newline at end of file

```

También se le puede indicar un commit en particular. Recordando los commit realizados hasta el momento:

```git
$ git log --oneline
2b0fa02 (HEAD -> master) comprobacion correcta ejecucion programa
623c3dd hola mundo
```

Por ejemplo, para que muestro solamente el commit inicial: `git show 623c3dd`.

```git
$ git show 623c3dd
commit 623c3dd1733d2370dca2952066dd3578180e66b7
Author: usuario <usuario@ejemplo.com>
Date:   Wed Nov 4 11:19:48 2020 +0100

    hola mundo

diff --git a/.gitignore b/.gitignore
new file mode 100644
index 0000000..b3bf457
--- /dev/null
+++ b/.gitignore
@@ -0,0 +1,3 @@
+/.vscode
+readme.md
+*.exe
\ No newline at end of file
diff --git a/main.cpp b/main.cpp
new file mode 100644
index 0000000..0e0deff
--- /dev/null
+++ b/main.cpp
@@ -0,0 +1,7 @@
+#include <iostream>
+
+int main(){
+
+    std::cout<< "Hola mundo!"<<std::endl;
+
+}

```

## Creando Commits

Como ya se introdujo inicialmente, `git status` nos va a indicar si hay cambios en el repositorio con respecto al anterior commit:

Si no hay cambios indica:

```git
$ git status
On branch master
nothing to commit, working tree clean
```

Si se han modificado ficheros:

```git
$ git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   main.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```

si se han modificado ficheros, se pueden añadir para hacer un commmit mediante las siguientes ordenes:

* Para añadir todos los ficheros modificados: `git add .`.
* Para añadir solo un fichero en concreto:  `git add <nombre fichero>`

En muchas ocasiones interesa hacer commits separados de grupos de archivos diferentes, para indicar comentarios específicos en el mensaje del commit sobre el grupo referenciado.

Por ejemplo, en este caso, voy a añadir para commit el fichero `main.cpp`:

```git
$ git add main.cpp
```

Para deshacer archivos añadidos (no incluidos en ningún commit aún), se puede usar de forma similar a `git add <nombre fichero>` el comando `git rm --cached <nombre fichero>`.

Ahora, `git status` indica que un fichero se ha incluido para hacerle commit:

```git
$ git status
On branch master
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   main.cpp
```

### __git commit__

En este momento, se pueden añadir mas archivos que estuvieran modificados (no es el caso de este ejemplo) o simplemente realizar el commit.

Para realizar el commit, tecleamos el comando: `git commit`.

```git
$ git commit -m "Secuencia de 0 a 9"
[master 78e054f] Secuencia de 0 a 9
 1 file changed, 10 insertions(+), 1 deletion(-)
```

Si no se indica en el comando `-m "mensaje..."`, automáticamente aparecerá el editor de texto que tengamos configurado para que indiquemos un mensaje. En ese caso, el commit no se realiza hasta que no se escriba el mensaje, guardemos y cerremos el editor. Incluir un mensaje es obligatorio.

Tras el commit, `git status` debería volver el mensaje indicado anteriormente: `On branch master nothing to commit, working tree clean`

Para comprobar que el commit se ha realizado correctamente, se puede emplear el commando `git log`.

```git
$ git log --oneline
78e054f (HEAD -> master) Secuencia de 0 a 9
2b0fa02 comprobacion correcta ejecucion programa
623c3dd hola mundo
```

### __git diff__


`git diff` muestra los actuales cambios (no incluidos en ningún commit) con respecto al anterior commit. Si no hay ningún cambio este comando no devolverá ninguna respuesta.

Si se realiza algún cambio en algún archivo y se ejecuta el comando `git diff`se muestra la siguiente información:

```git
$ git diff
diff --git a/main.cpp b/main.cpp
index d60e9ca..8aad0c4 100644
--- a/main.cpp
+++ b/main.cpp
@@ -1,19 +1,26 @@
 #include <iostream>

-void imprime_secuencia(){
+int imprime_secuencia(){

-    for (int i = 0; i<10; i++)
+    int sum = 0;
+    for (int i = 0; i<10; i++){
         std::cout<< i << " ";
+        sum = sum + i;
+    }
     std::cout<<std::endl;
+
+    return sum;
 }

 int main(){
```

Tras añadir los cambios (`git add .`) y hacer el commit de los mismos (`git commit`) `git diff no devuelve ningún resultado.

El comando `git diff` es equivalente a `git log -p` ( o lo que es lo mismo `git log --patch`).


### __.gitignore__

En ocasiones se suele incluir el archivo `.gitignore` en los repositorios de git. Este nos permite indicar que ficheros no queremos que se añadan para un commit usando el comando `git add .`.

Por ejemplo, para que no se indique ningún fichero del tipo `.txt` y del tipo `.exe`, tenemos que incluir en el fichero `.gitignore` lo siguiente:

```git
*.exe
*.txt
```

Por el contrario, si no queremos que se incluyan ciertas carpetas, podemos añadirle la dirección de la carpeta. Por ejemplo:

```git
/project/build
/.vscode
```

En este ejemplo, no se podrá añadir a git la subcarpeta build, ni el fichero de configuración de vscode.

En el siguiente enlace se pueden encontrar diversas plantillas de `.gitignore` para diversos lenguajes: https://github.com/github/gitignore

## Etiquetas, ramas y fusion de ramas (tag, branch y merge)

### __git tag__ (etiquetas)

Permite añadir etiquetas personalizadas a los commits deseados. El comando a emplear es el siguiente: `git tag -a <nuestra_etiqueta> <referencia_sha_del_commit>`.

Si no se le indica la referencia del commit, le añade la etiqueta al último commit realizado.

Cuando se ejecuta el comando indicado, se abre un editor de texto para indicar un comentario, de forma similar a como ocurre cuando se realiza un commit.

Veamos un ejemplo. Si se tiene la siguiente lista de commits en un proyecto:

```git
$ git log --oneline
75a579d (HEAD -> master) Se ha requerido conocer la suma de la secuencia
78e054f Secuencia de 0 a 9
2b0fa02 comprobacion correcta ejecucion programa
623c3dd hola mundo

```

y se ejecuta el siguiente comando:

```git
git tag -a v1.0 78e054f
```

Se puede ver a continuación como se ha añadido al penúltimo commit la etiqueta `v1.0`:

```git
$ git log --oneline
75a579d (HEAD -> master) Se ha requerido conocer la suma de la secuencia
78e054f (tag: v1.0) Secuencia de 0 a 9
2b0fa02 comprobacion correcta ejecucion programa
623c3dd hola mundo
```

Para borrar cualquier etiqueta, solo hay que sustituir la `a` por una `d` en el anterior comando. Ejemplo:

```git
$ git tag -d v1.0
Deleted tag 'v1.0' (was ff31424)
```

A continuación, se puede observar que ya no aparece la anterior etiqueta.

```git
$ git log --oneline
75a579d (HEAD -> master) Se ha requerido conocer la suma de la secuencia
78e054f Secuencia de 0 a 9
2b0fa02 comprobacion correcta ejecucion programa
623c3dd hola mundo
```

### Ramas (branch)

Una rama es una bifurcación del código donde queremos implementar funciones experimentales, de las que no estamos seguros de incluir en el proyecto final.

El comando `git branch` nos indica las ramas existentes en el repositorio, indicando con un `*` la rama en la que se sitúa actualmente nuestra copia local.

Hasta ahora, no tenemos ninguna rama, por lo que la vamos a crear usando el comando:

`git branch <nombre de la rama a crear>`

Por ejemplo:

```git
$ git branch pruebas
$ git branch
* master
  pruebas
```

Como se puede comprobar, ahora el comando `git brach` muestra dos ramas. Y además, indica que estamos situados en la rama master.

Para cambiar a la rama pruebas hay que usar el comando `git checkout <nombre_rama_situarse>`

```git
$ git checkout pruebas
Switched to branch 'pruebas'

$ git branch
  master
* pruebas
```

Ahora, la cabecera del repositorio apuntará a las dos ramas creadas, como puede comprobarse con el comando `git log`:

```git
$ git log --oneline
75a579d (HEAD -> pruebas, master) Se ha requerido...
2b0fa02 comprobacion correcta ejecucion programa
623c3dd hola mundo
```

Para borrar una rama, hay que situarse en una rama diferente a la que se quire borrar. Se puede realizar con el comando `git branch -d <nombre_rama_eliminar>`.

En el caso de este ejemplo:

```git

$ git checkout master
Switched to branch 'master'

$ git branch -d pruebas
Deleted branch pruebas (was 75a579d).

$ git branch
* master
```

Comprobamos que el último comando solo devuelve la rama master

Si la rama tiene contenido (contiene algún commit) no se podrá borrar con el anterior comando. Aunque siempre se puede forzar el borrado, aún teniendo contenido, empleando el mismo comando con la `D` en mayúscula: `git branch -D <nombre_rama_eliminar>`. Usa este comando con cuidado. Puedes arrepentirte de usarlo y no es necesario eliminar ramas que no nos han llevado a ningún resultado útil (por el momento).

Hasta en el momento, en este apartado, se han mostrado los comando para crear una nueva rama partiendo desde el último commit. Pero también se puede crear una rama partiendo de un commit previo. Para ello hay que indicar el cod. SHA del commit a partir del que queremos crear la rama: `git branch <nombre_rama_crear> <sha_commit_partida>`. Por ejemplo:

```git
$ git branch pruebas 78e054f

$ git log --oneline
75a579d (HEAD -> master) Se ha requerido conocer la suma de la secuencia
78e054f (pruebas) Secuencia de 0 a 9
2b0fa02 comprobacion correcta ejecucion programa
623c3dd hola mundo
```

Se comprueba, llamando a `git log`, que el commit `78e054f` es el inicio de la rama pruebas.

Si nos situamos en la rama pruebas con `git checkout`, iremos al commit `78e054f`. En este caso retrocederemos en un commit y no veremos los últimos cambios que habíamos realizado sobre nuestros archivos.

Tras situarnos en pruebas, podemos trabajar en esta rama y hacer cambios en la misma, que de forma seguida se registraran a esta rama con un commit. Por ejemplo:

```git
$ git checkout pruebas
Switched to branch 'pruebas'

$ git log --oneline
78e054f (HEAD -> pruebas) Secuencia de 0 a 9
2b0fa02 comprobacion correcta ejecucion programa
623c3dd hola mundo

$ git status
On branch pruebas
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   main.cpp

$ git add .

$ git commit -m "Multiplicacion secuencia"
[pruebas 2091932] Multiplicacion secuencia
 1 file changed, 27 insertions(+), 3 deletions(-)

```

Ahora mismo tenemos un commit en nuestra rama pruebas. Existe un comando que permite ver de una forma más visual el diferente recorrido de las ramas: `git log --graph --all --oneline`

```git
$ git log --graph --all --oneline
* 2091932 (HEAD -> pruebas) Multiplicacion secuencia
| * 75a579d (master) Se ha requerido conocer la suma...
|/
* 78e054f Secuencia de 0 a 9
* 2b0fa02 comprobacion correcta ejecucion programa
* 623c3dd hola mundo
```

Mediante `|`, `/`, `\` y `*` se muestran los recorridos de las diferentes ramas en el repositorio.

### Fusión de dos ramas (merge)

Si consideramos que los cambios realizados sobre nuestra rama (`pruebas` en este caso) son estables y útiles para nuestro proyecto, los podemos incorporar a la rama master. Para esto, estado sobre la rama master, ejecutamos el siguiente comando: `git merge <nombre_rama_fusionar>`.

Pero antes de ello, se pueden hacer algunos commits más a cada una de las ramas para que el comando `git log --graph --all --oneline` muestre más claramente commits en ambas ramas. De tal forma, que quede algo similar a esto:

```git
$ git log --graph --all --oneline
* 0a8a2fe (HEAD -> master) Cambio titulo
* 75a579d Se ha requerido conocer la suma de la secuencia
| * 94feed9 (pruebas) Usuario indica máximo
| * 2091932 Multiplicacion secuencia
|/
* 78e054f Secuencia de 0 a 9
* 2b0fa02 comprobacion correcta ejecucion programa
* 623c3dd hola mundo
```

Ahora si ejecutamos `git --merge pruebas` aparece el siguiente mensaje:

```git
$ git merge pruebas
Auto-merging main.cpp
CONFLICT (content): Merge conflict in main.cpp
Automatic merge failed; fix conflicts and then commit the result.
```

Se produce un conflicto, ya que en ambas ramas se ha trabajado sobre el mismo archivo. Si en las diferentes ramas se trabaja sobre archivos diferentes, la fusión de las ramas se realiza automáticamente, sin que necesite nuestra supervision. En caso contrario, deberemos encargarnos de resolver los conflictos debido a la divergencia entre los archivos a unir.

### Resolución de conflictos

Tras la aparición del mensaje de conflicto, si abrimos el archivo (o los archivos) a los que se refiere el mensaje, podremos ver una serie de caracteres:

* `<<<<<<< HEAD`: Lo que aparece debajo pertenece exclusivamente a la actual rama (master).
* `|||||||`: Las lineas de debajo son comunes en ambas ramas.
* `=======`: final de lineas comunes
* `>>>>>>>`: indica el final del contenido exclusivo de la otra rama (a fusionar)

Por ejemplo, vscode contiene una serie de resaltado en colores que nos ayuda a realizar la resolución del conflicto.

Hay que ir revisando cada uno de los conflictos, y decidir que contenido queremos mantener en la fusión de las ramas.

Una vez corregidos los conflictos, se tienen que añadir los cambios y hacer un commit pare que finalice la operación de `git merge`:

```git
$ git add .

$ git status
On branch master
All conflicts fixed but you are still merging.
  (use "git commit" to conclude merge)

Changes to be committed:
        modified:   main.cpp

$ git commit
[master 0728f8b] Merge branch 'pruebas'

$ git log --graph --all --oneline
*   0728f8b (HEAD -> master) Merge branch 'pruebas'
|\
| * 94feed9 (pruebas) Usuario indica máximo
| * 2091932 Multiplicacion secuencia
* | 0a8a2fe Cambio titulo
* | 75a579d Se ha requerido conocer la suma de la secuencia
|/
* 78e054f Secuencia de 0 a 9
* 2b0fa02 comprobacion correcta ejecucion programa
* 623c3dd hola mundo

```

`git log --graph --all --oneline` muestra gráficamente la fusión de las ramas.

## Cambios en último commit

Si no hay cambios con respecto al último commit, `git commit --amend` nos permite modificar el mensaje de éste.

Además, también permite incluir algún cambio nuevo en el último commit, si es que no nos interesa incluirlo en uno nuevo. Para ello antes hay que añadir los cambios  y entonces ejecutar `git commit --amend`.

### Volviendo a un commit determinado

Si estamos trabajando en una nueva funcionalidad, y no nos da el resultado esperado, con `git revert <SHA>` podemos volver a un commit anterior. el comando revert crea un commit con cambios que se tengan realizados hasta el momento y nos devuelve al estado del commit indicado

### Revertir commits

Si queremos deshacer cambios hasta algún commit en concreto, podemos usar el commando `git revert <SHA>`. Este permite realizar las siguientes acciones:

* convierte el commit indicado, en el último de la rama
* deshace los commits anteriores

 El comando permite algunas opciones mediante sufijos:
 
* `git revert --soft <SHA>` pasa todos los cambios de commits anteriores a añadido para realiza un nuevo commit.
* `git revert --mixed <SHA>` pasa todos los cambio de los commits anteriores a el estado actual. Esta es la operación por defecto.
* `git revert --hard <SHA>` borra todos los commits anteriores.
