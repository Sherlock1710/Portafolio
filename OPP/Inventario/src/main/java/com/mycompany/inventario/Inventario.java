/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.inventario;

import gui.Agregar;
import gui.Principal;
import java.util.LinkedList;
/**
 *
 * @author USER
 */
public class Inventario {

    public static void main(String[] args) {
        
        LinkedList<Producto> productos = new LinkedList<>();
        Principal p = new Principal();
        Producto prod = new Producto();
        
        Producto nuevo = prod.agregarProducto(1, "Coca cola",5500 , 30);
        productos.add(nuevo);
        
        System.out.println("-------------PRUEBA-------------");
        for(Producto producto:productos){
            System.out.println("Id: "+producto.getId());
            System.out.println("Nombre: "+ producto.getNombre());
            System.out.println("Precio: "+producto.getPrecio());
            System.out.println("Unidades: "+producto.getUnidades());
        }
        
        p.setVisible(true);
        p.setLocationRelativeTo(null);
        
    }
}
