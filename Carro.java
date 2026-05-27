/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.veiculos;

import java.util.Date;

/**
 *
 * @author Academico
 */
public class Carro {
    private String marca;
    private String modelo;
    private Date data;
    private double preco;
    private boolean ligado;
    
    
    public Carro(String marca, String modelo, Date data, double preco){
        this.marca = marca;
        this.modelo = modelo;
        this.data = data;
        this.preco = preco;
    }
    
    public String getMarca(){
        return this.marca;
    }
    public void setMarca(String marca){
        this.marca = marca;
    }
    public String getModelo(){
        return this.modelo;
    }
    public void setModelo(String modelo){
        this.modelo = modelo;
    }
    public Date getData(){
        return this.data;
    }
    public void setData(Date data){
        this.data = data;
    }
    public double getPreco(){
        return this.preco;
    }
    public void setPreco(double preco){
        this.preco = preco;
    }
    public boolean getLigado(){
        return this.ligado;
    }
    public void setLigado(boolean ligado){
        this.ligado = ligado;
    }
    
    public void ligar(){
        this.ligado = true;
        System.out.println("Carro ligado");
    }
    public void desligar(){
        this.ligado = false;
        System.out.println("Carro desligado");
    }
}


