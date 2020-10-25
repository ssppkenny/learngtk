#include <gtk/gtk.h>
#include <stdio.h>


static void key_press(GtkWidget *window,  gpointer data){
    char *string = NULL;
    printf("clicked\n");
    GtkWidget* w = data;
    g_object_get(G_OBJECT(w), "title", &string, NULL);
    printf("%s\n", string);
}

static void destroy(GtkWidget *window, GtkLabel *label) {
    gtk_main_quit();
}

static gboolean delete_event(GtkWidget *window, GdkEvent *event, gpointer data) {
    return FALSE;
}

int main(int argc, char *argv[]){
    GtkWidget *window, *label, *button;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hello World!");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 200,100);
    gtk_window_set_resizable((GtkWindow*)window, FALSE);

    button = gtk_button_new_with_label("My Button");
    gtk_container_add(GTK_CONTAINER(window), button);
    int n = 100;

    
    //g_object_set(window, "title", "MyTitle", NULL);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(key_press), window);

    //label = gtk_label_new("Hello World label");
    //gtk_label_set_selectable(GTK_LABEL(label), FALSE);

    //gtk_container_add(GTK_CONTAINER(window), label);


    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}


