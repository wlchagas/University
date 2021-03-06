import java.util.HashMap;

public class CommandNew implements Command
{
	public void novo(String nome, Long id, HashMap<Long,String> map)
	{
		map.put(id, nome);
	}

	@Override
	public void execute(HashMap<Long, String> map, Long id, String nome) {
		novo(nome, id, map);
	}
}