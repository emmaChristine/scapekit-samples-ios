//
//  ViewController.swift
//  pixscape-ios
//
//  Created by bils on 01/12/2018.
//  Copyright © 2018 Scape Technologies. All rights reserved.
//

import UIKit
import ScapeKit

final class ARViewController: UIViewController {

    override var preferredStatusBarStyle : UIStatusBarStyle {
        return .lightContent
    }
    
    lazy var arView: SCKArView = {
        return SCKArView()
    }()
    
    lazy var scapeButton: UIButton = {
        let button = UIButton(frame: CGRect(x: self.view.bounds.width/2 - 50,
                                            y: self.view.bounds.height - 50,
                                            width: 100,
                                            height: 50))
        button.backgroundColor = .green
        button.setTitle("Localize", for: .normal)
        button.addTarget(self, action: #selector(localizeWithSensorsAndVisionEngine), for: .touchUpInside)
        return button
    }()
    
    private var arSession: SCKArSession?
    private var scapeSession: SCKScapeSession?
    private var scapeClient: SCKScapeClient
    
    init(scapeClient: SCKScapeClient) {
        self.scapeClient = scapeClient
        
        super.init(nibName: nil, bundle: nil)
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        NotificationCenter.default.addObserver(self,
                                               selector: #selector(didBecomeActive),
                                               name: UIApplication.didBecomeActiveNotification,
                                               object: nil)
        
        self.view.addSubview(arView)
        self.view.addSubview(scapeButton)
        
        setupAr()
        setupScape()
    }
    
    override func viewWillLayoutSubviews() {
        super.viewWillLayoutSubviews()
        
        arView.frame = view.bounds
    }
    
    func setupAr() {
        arSession = scapeClient.arSession?.withArView(view: arView)
        arSession?.setDebugMode(false)
        arSession?.resetTracking()
    }
    
    func setupScape() {
        scapeSession = scapeClient.scapeSession
    }
    
    @objc func didBecomeActive() {
        arSession?.resetTracking()
    }
    
    /**
     * Get measurements using raw sensors only
     */
    @objc func localizeWithRawSensors(sender: UIButton!) {
        scapeSession?.getMeasurements(geoSourceType: SCKGeoSourceType.rawSensors,
                                      deviceLocationMeasurementsUpdated: { measurements in
            let gpsCoordinates = "\(String(describing: measurements?.coordinates?.latitude)) \(String(describing: measurements?.coordinates?.longitude)) "
            print("Retrieving GPS coordinates: \(gpsCoordinates)")
        },
                                      deviceMotionMeasurementsUpdated: { measurements in
                                        
        },
                                      scapeMeasurementsUpdated: { measurements in
                                        
        },
                                      cameraTransformUpdated: { transform in
                                        
        },
                                      sessionError: { state, error in
            print("Could not retrieve measurements: \(error)")
        })
    }

    
    /**
     * Get measurements using raw sensors and Scape Vision Engine
     */
    @objc func localizeWithSensorsAndVisionEngine(sender: UIButton!) {
        scapeSession?.getMeasurements(geoSourceType: SCKGeoSourceType.rawSensorsAndScapeVisionEngine,
                                      deviceLocationMeasurementsUpdated: { measurements in
            let gpsCoordinates = "\(String(describing: measurements?.coordinates?.latitude)) \(String(describing: measurements?.coordinates?.longitude)) "
            print("Retrieving GPS coordinates: \(gpsCoordinates)")
        },
                                      deviceMotionMeasurementsUpdated: { measurements in
                                        
        },
                                      scapeMeasurementsUpdated: { measurements in
            let scapeCoordinates = "\(String(describing: measurements?.coordinates?.latitude)) \(String(describing: measurements?.coordinates?.longitude)) "
            print("Retrieving Scape coordinates: \(scapeCoordinates)")
        },
                                      cameraTransformUpdated: { transform in
                                        
        },
                                      sessionError: { state, error in
            print("Could not retrieve measurements: \(error)")
        })
    }
}

