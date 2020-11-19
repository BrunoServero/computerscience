package com.carros.entity;

public class Carro {

    private int id;
    private String modelo;
    private String marca;
    private int anoFab;
    private int anoMod;
    private int km;
    private int preco;
    private String cor;
    private String listaAcessorio;

    public Carro(){}
    public Carro(int id, String modelo, String marca, int anoFab, int anoMod, int km, int preco, String cor, String listaAcessorio){
        this.id = id;
        this.modelo = modelo;
        this.marca = marca;
        this.anoFab = anoFab;
        this.anoMod = anoMod;
        this.km = km;
        this.preco = preco;
        this.cor = cor;
        this.listaAcessorio = listaAcessorio;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public int getAnoFab() {
        return anoFab;
    }

    public void setAnoFab(int anoFab) {
        this.anoFab = anoFab;
    }

    public int getAnoMod() {
        return anoMod;
    }

    public void setAnoMod(int anoMod) {
        this.anoMod = anoMod;
    }

    public int getKm() {
        return km;
    }

    public void setKm(int km) {
        this.km = km;
    }

    public int getPreco() {
        return preco;
    }

    public void setPreco(int preco) {
        this.preco = preco;
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    public String getListaAcessorio() {
        return listaAcessorio;
    }

    public void setListaAcessorio(String listaAcessorio) {
        this.listaAcessorio = listaAcessorio;
    }
};