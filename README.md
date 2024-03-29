<h1 align="center">Welcome to Flux 👋</h1>
<p>
  <img alt="Windows Status" src="https://github.com/just-a-mango/flux/actions/workflows/win-ci.yml/badge.svg"/>
  <img alt="Linux Status" src="https://github.com/just-a-mango/flux/actions/workflows/linux-ci.yml/badge.svg"/>
  <img alt="Version" src="https://img.shields.io/badge/version-WIP-blue.svg"/>
  <img alt="Language" src="https://img.shields.io/badge/language-C++14-purple.svg"/>
</p>

<img src="./website/icon.png" width=150 align="right">

An easy-to-use work-in-progress programming language written in C++

### 🏠 [Homepage](https://github.com/just-a-mango/flux)


## 🪶 Description
**Fl**ux **wa**s **fir**st **writt**en **i**n **Pyth**on, **jus**t **lik**e **m**y **ver**y **fir**st **programmi**ng **langua**ge **Man**go. **Aft**er **som**e **tim**e **an**d **evaluati**on, I **decid**ed **no**t **t**o **us**e **Pyth**on **anymo**re **fo**r **thi**s **proje**ct **becau**se **o**f **it**s **performan**ce **an**d **hig**h-**lev**el **limitatio**ns, **an**d **t**o **us**e C++ **inste**ad. C++ **developme**nt **i**s **slow**er **becau**se I **a**m **muc**h **les**s **experienc**ed, **bu**t **loo**ks **ver**y **promisi**ng, **wit**h **astonishi**ng **performan**ce **a**t **th**e **mome**nt. **Havi**ng **tha**t **sai**d, a **worki**ng **relea**se **o**f **Flu**x **is**n't **expect**ed **befo**re **qui**te **som**e **tim**e..


## ⬇️ Downloading and installing
### // DOESN'T WORK - USE CMAKE INSTEAD
Head over to the ['Actions'](https://github.com/just-a-mango/flux/actions) tab of this repository. Select the latest Windows/Linux CI action (depending on your OS) and click on the 'Artifacts'. Download the .zip file and extract its content somewhere you'd like Flux to be installed. Optionally, add this folder to the PATH system variable so you can run it anywhere, and you're done.
To run it, simply do:
```sh
flux(.exe/.out, depends on your OS) <flux file>
```


## 🚀 Building and running
### // DOESN'T WORK - USE CMAKE INSTEAD
**This part is only recommended to those who have cloned this repository**

**Build and run**:

```sh
build-scripts/build // -> windows
g++ flux.cpp -o flux Wno-multichar -Wno-overflow // -> linux
```

**Build and run with all warnings shown and optimizations**:

```sh
build-scripts/build -production // -> windows
g++ flux.cpp -o flux -Ofast -Wall -Wextra -Wno-multichar -Wno-overflow // -> linux
```

**Only run**:

```sh
flux <file> -> windows/linux
```

## 📚 Documentation
  As Flux is still very early, documentation might change later in the future.
  For now, you can find the documentation [here](https://github.com/just-a-mango/flux/blob/54d07fd07d359f3f0f0232120adde8be6b77b7da/docs/documentation.md), and you can find a list of everything that doesn't currently work [here](https://github.com/just-a-mango/flux/wiki/What-doesn't-work-yet)

## 🤝 Contributing

Contributions, issues and feature requests are welcome !<br/>Feel free to check [issues page](https://github.com/just-a-mango/flux/issues).
