using UnityEngine;



public class GameHandler : MonoBehaviour{


    private void Start(){
        Mesh mesh = new Mesh();

        GameObject = new GameObject("Mesh", typeof(MeshFilter), typeof(MeshRenderer));
        gameObject.transform.localScale = new Vector3(30, 30, 1);
    }
}