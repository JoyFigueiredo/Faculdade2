package trabalhopc2.FabricaDeTecidos.view;


public interface IViewCrud<T> {

    public T create(T l);

    public T edit(T t);

    public void list(T[] t);

    public String delete();

    public String search();

    public void read(T t);
}
